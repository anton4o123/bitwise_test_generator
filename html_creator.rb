require "cgi"
require "uri"

cgi=CGI.new("html4")
count=1

Dir.chdir("web")

File.open("count.txt").each do |line|
	count=line.to_i
end

rows=Array.new(12, Array.new(8))

i=1
while i<=count
	j=1
	while j<=12
		k=1
		File.open("#{i}/#{j}.txt").each do |line|
			rows[j-1][k-1]=line
			k+=1
		end
		j+=1
	end
	
	puts rows[0][0]
	
	html=cgi.html{
		"\n"
		cgi.head{
			cgi.title{"Test #{i}"}
		}+
		
		cgi.body{
			j=1
			cgi.table{
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}+
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}+
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}+
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}+
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}+
				cgi.tr {
					cgi.td {
					
					}+
					cgi.td {
					
					}
				}
			}
		}
	}
	i+=1
end

puts html
