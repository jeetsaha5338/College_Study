echo "Enter date:"
read d
read m
read y
case $m in
1|3|5|7|8|10|12)	if [ $d -gt 31 -o $d -lt 0 ]
						then echo "invalid"
						else echo "valid"
					fi;;


2) 					if [ `expr $y % 400` -eq 0 -o `expr $y % 4` -eq 0 -a `expr $y % 100` -ne 0 ]
					then
						if [ $d -gt 29 -o $d -lt 0 ]
						then echo "invalid"
						else echo "valid"
						fi
					else
						if [ $d -gt 28 -o $d -lt 0 ]
						then echo "invalid"
						else echo "valid"
						fi
					fi;;

4|6|9|11) 			if [ $d -gt 30 -o $d -lt 0 ]
						then echo "invalid"
						else echo "valid"
					fi;;
			
*)	echo "invalid"
esac
