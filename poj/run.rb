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
end.parse!

# search the files
files = Set.new

Find.find(File.dirname(folder)) do |filename|
  q = filename.split('/')
  if q.size > 2
    files.add q[1].split('p')[1].to_i
  end
end
if files.size == 0
  p 'meidongxi ni paoge jiba, shabi'
  exit
end

# determine the number
if options[:number] == nil
  options[:number] = files.max
end

cmake = "
cmake_minimum_required(VERSION 3.3)
project(myoj)

add_executable(myoj poj//p#{options[:number]}//p#{options[:number]}.cpp)
add_compile_options(-std=c++11)
"

File.open('../CMakeLists.txt', 'w') do |f|
  f.puts(cmake)
end


require 'fileutils'
FileUtils.cp "p#{options[:number]}\\sample_input.txt",'../cmake-build-debug/sample_input.txt'
