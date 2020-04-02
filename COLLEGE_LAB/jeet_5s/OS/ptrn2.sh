# * * *
# *   *
# * * *
echo "enter:"
read n
x=5
y=2

for((i=1;i<=n;i=i+1))
do
	a=$y
	k=`echo "($x-1)+$i"|bc`
	if [ $i -eq 1 -o $i -eq $n ]
	then
	 	for((j=1;j<=n;j=j+1))
		 do
			tput cup $k $a
			echo "*"
			a=`echo "$a+2"|bc`
	 	done
	else
		tput cup $k $a
		echo "*"
		a1=`echo "($a-2)+(2*$n)"|bc`
		tput cup $k $a1
		echo "*"
	fi
done

