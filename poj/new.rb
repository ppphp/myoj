require "optparse"
require "find"
require "set"

# parse the args
folder = File.dirname(__FILE__)

options = {}
option_parser = OptionParser.new do |opts|
  opts.banner = 'diao bu diao'
  options[:cover] = false
  opts.on('-n NUMBER', '--number NUMBER', 'POJ number') do |value|
    options[:number] = value
  end
  opts.on('-c', '--cover', 'cover the origin') do
    options[:cover] = true
  end
end.parse!

files = Set.new

Find.find(File.dirname(folder)) do |filename|
  p filename
  q = filename.split('/')
  if q.size > 2
    files.add q[1].split('p')[1].to_i
  end
end

if options[:number] == nil
  options[:number] = files.size > 0 ? files.max : 999
end

cpp_s = "
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}
"

md_s = "
#p#{options[:number]}


##Description


##Input


##Output



#结果



#解答



"
Dir.mkdir("p#{options[:number]+1}")
cpp = File.new("p#{options[:number]+1}\\p#{options[:number]+1}.cpp",'w')
cpp.puts(cpp_s)
cpp.print
cpp.close
md = File.new("p#{options[:number]+1}\\p#{options[:number]+1}.cpp", 'w')
md.puts(md_s)
md.close

p options.inspect
