echo "enter no. of element:"
read n
f=0
echo "enter the elements:"
for((i=0;i<n;i++))
do
	read x
	a[i]=$x
done
echo "enter searching element:"
read k
for((i=0;i<n;i++))
do
	if [ $k -eq ${a[i]} ]
		then
	 		f=`echo "$i+1"|bc`
			break
	fi
done
if [ $f -eq 0 ]
	then
		echo "not found"
	else
		echo "found at $f"
fi
