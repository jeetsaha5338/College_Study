echo "Enter The no. of Elements: "
read n
echo "Enter the elements:"
for((i=0;i<n;i++))
do
	read x
		a[i]=$x
done
for((i=0;i<n-1;i++))
do
	if [ ${a[i]} -gt ${a[i+1]}  -o ${a[i]} -eq ${a[i+1]} ]
	then  f1=1
	else  f1=0
	break
	fi
done
for((i=0;i<n-1;i++))
do
	if [ ${a[i]} -lt ${a[i+1]}  -o ${a[i]} -eq ${a[i+1]}	]
	then f2=2
	else f2=0
	break
	fi
done

if [ $f1  -eq 1 ]
then echo "D"
elif [ $f2 -eq	2 ]
then echo "A"
else 
	echo "Not"						
fi
