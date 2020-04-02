echo "ENTER THE YEAR=>"
read y
if [ `expr $y % 400` -eq 0 -o `expr $y % 4` -eq 0 -a `expr $y % 100` -ne 0 ]
	then echo "IT'S"
else
	echo "IT'S NOT"
fi
