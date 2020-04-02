echo "Enter The no. of Elements: "
read n
f=0
echo "Enter the elements:"
for((i=0;i<=n;i++))
do
	read x
		a[i]=$x
done
echo	"Enter the Search Elements"	
read k
for((i=0;i<=n;i++))
do
	if [ $k -eq ${a[ i ]} ]
		then 
				f=`echo "$i+1"|bc
				break
	fi
done
if [ $f -eq 0 ]
then 
		echo "not found"
	else
		echo "found at $f"	
fi				
