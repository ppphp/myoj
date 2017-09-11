require "optparse"
require "find"
require "set"

# parse the args
folder = File.dirname(__FILE__)

options = {}
option_parser = OptionParser.new do |opts|
  opts.banner = 'diao bu diao'
  options[:cover] = false  # for the question with selected number is wirtten
  opts.on('-n NUMBER', '--number NUMBER', 'POJ number') do |value|
    options[:number] = value
  end
  opts.on('-c', '--cover', 'cover the origin') do
    options[:cover] = true
  end
end.parse!

# search the files
files = Set.new

Find.find(File.dirname(folder)) do |filename|
  q = filename.split('/')
  if q.size > 2
    files.add q[1].split('p')[1].to_i
  end
end

# determine the number
if options[:number] == nil
  options[:number] = files.size > 0 ? files.max : 999
end

# determine whether new code is written, if not, do not change
if options[:number] != 999
  cpp_old = File.open("p#{options[:number]}\\p#{options[:number]}.cpp",'r').sysread(150)
end

cpp_s = "
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}
"

if cpp_old == cpp_s
  exit
end

# generate markdown file
require "rubygems"
require "nokogiri"
require 'open-uri'
uri = "http://poj.org/problem?id=#{options[:number] + 1}"
doc = Nokogiri::HTML(open(uri))
# parse html
name = doc.css('.ptt').first.content
description = doc.css('.ptx')[0].content.gsub(/\r+/,"\n\n")
input = doc.css('.ptx')[1].content.gsub(/\r+/,"\n\n")
output = doc.css('.ptx')[2].content.gsub(/\r+/,"\n\n")
sample_input_s = doc.css('.sio')[0].content.gsub(/\r\n/,"\n")
sample_output_s = doc.css('.sio')[1].content.gsub(/\r\n/,"\n")
md_s = "
#p#{options[:number]+1}
#{name}

##Description
#{description}

##Input
#{input}

##Output
#{output}


#结果



#解答



"
Dir.mkdir("p#{options[:number]+1}")
cpp = File.new("p#{options[:number]+1}\\p#{options[:number]+1}.cpp",'w')
cpp.puts(cpp_s)
cpp.print
cpp.close
md = File.new("p#{options[:number]+1}\\p#{options[:number]+1}.md", 'w')
md.puts(md_s)
md.close
sample_input = File.new("p#{options[:number]+1}\\sample_input.txt", 'w')
sample_input.puts(sample_input_s)
sample_input.close
sample_output = File.new("p#{options[:number]+1}\\sample_output.txt", 'w')
sample_output.puts(sample_output_s)
sample_output.close
p options.inspect
