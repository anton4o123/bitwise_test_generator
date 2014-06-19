require "cgi"
require "uri"

cgi=CGI.new("html4")
count=1

Dir.chdir("web")

File.open("count.txt").each do |line|
	count=line.to_i
end

rows=Hash.new
rows_res=[]

i=1
while i<=count
	j=1
	while j<=12
		k=1
		File.open("#{i}/#{j}.txt").each do |line|
			rows[[j-1, k-1]]=line
			k+=1
		end
		
		k=1
		File.open("#{i}/#{j}-res.txt") do |file|
			rows_res[j-i]=file.gets
		end
		
		`rm #{i}/#{j}-res.txt`
		`rm #{i}/#{j}.txt`
		j+=1
	end
	
	html=cgi.html{
		"\n"
		cgi.head{
			cgi.title{"Test #{i}"}
		}+
		
		cgi.body{
			j=1
			cgi.table("border"=>"1"){
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[0,0]]}"}+
						cgi.pre{"#{rows[[0,1]]}"}+
						cgi.pre{"#{rows[[0,2]]}"}+
						cgi.pre{"#{rows[[0,3]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[1,0]]}"}+
						cgi.pre{"#{rows[[1,1]]}"}+
						cgi.pre{"#{rows[[1,2]]}"}+
						cgi.pre{"#{rows[[1,3]]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[2,0]]}"}+
						cgi.pre{"#{rows[[2,1]]}"}+
						cgi.pre{"#{rows[[2,2]]}"}+
						cgi.pre{"#{rows[[2,3]]}"}+
						cgi.pre{"#{rows[[2,4]]}"}+
						cgi.pre{"#{rows[[2,5]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[3,0]]}"}+
						cgi.pre{"#{rows[[3,1]]}"}+
						cgi.pre{"#{rows[[3,2]]}"}+
						cgi.pre{"#{rows[[3,3]]}"}+
						cgi.pre{"#{rows[[3,4]]}"}+
						cgi.pre{"#{rows[[3,5]]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[4,0]]}"}+
						cgi.pre{"#{rows[[4,1]]}"}+
						cgi.pre{"#{rows[[4,2]]}"}+
						cgi.pre{"#{rows[[4,3]]}"}+
						cgi.pre{"#{rows[[4,4]]}"}+
						cgi.pre{"#{rows[[4,5]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[5,0]]}"}+
						cgi.pre{"#{rows[[5,1]]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[6,0]]}"}+
						cgi.pre{"#{rows[[6,1]]}"}+
						cgi.pre{"#{rows[[6,2]]}"}+
						cgi.pre{"#{rows[[6,3]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[7,0]]}"}+
						cgi.pre{"#{rows[[7,1]]}"}+
						cgi.pre{"#{rows[[7,2]]}"}+
						cgi.pre{"#{rows[[7,3]]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[8,0]]}"}+
						cgi.pre{"#{rows[[8,1]]}"}+
						cgi.pre{"#{rows[[8,2]]}"}+
						cgi.pre{"#{rows[[8,3]]}"}+
						cgi.pre{"#{rows[[8,4]]}"}+
						cgi.pre{"#{rows[[8,5]]}"}+
						cgi.pre{"#{rows[[8,6]]}"}+
						cgi.pre{"#{rows[[8,7]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[9,0]]}"}+
						cgi.pre{"#{rows[[9,1]]}"}+
						cgi.pre{"#{rows[[9,2]]}"}+
						cgi.pre{"#{rows[[9,3]]}"}+
						cgi.pre{"#{rows[[9,4]]}"}+
						cgi.pre{"#{rows[[9,5]]}"}+
						cgi.pre{"#{rows[[9,6]]}"}+
						cgi.pre{"#{rows[[9,7]]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows[[10,0]]}"}+
						cgi.pre{"#{rows[[10,1]]}"}+
						cgi.pre{"#{rows[[10,2]]}"}+
						cgi.pre{"#{rows[[10,3]]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows[[11,0]]}"}+
						cgi.pre{"#{rows[[11,1]]}"}+
						cgi.pre{"#{rows[[11,2]]}"}+
						cgi.pre{"#{rows[[11,3]]}"}
					}
				}
			}
		}
	}
	
	html_res=cgi.html{
		"\n"
		cgi.head{
			cgi.title{"Test #{i} Results"}
		}+
		
		cgi.body{
			j=1
			cgi.table("border"=>"1"){
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[0]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[1]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[2]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[3]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[4]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[5]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[6]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[7]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[8]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[9]}"}
					}
				}+
				cgi.tr {
					cgi.td {
						cgi.pre{"#{rows_res[10]}"}
					}+
					cgi.td {
						cgi.pre{"#{rows_res[11]}"}
					}
				}
			}
		}
	}
	
	File.open("#{i}/test.html", "w") do |file|
		file << html
	end
	
	File.open("#{i}/test_res.html", "w") do |file|
		file << html_res
	end
	
	i+=1
end
