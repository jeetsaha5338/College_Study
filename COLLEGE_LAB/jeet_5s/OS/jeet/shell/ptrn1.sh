#		*
#	*		*
#*		*		*
echo "enter:"
read n
x=5
y=1
for((i=1;i<=n;i=i+1))
do
	for((j=1;j<=i;j=j+1))
	do
		k2=`echo "(($n-$i)*2)+$y"|bc`
		a2=`echo "($x+$i)-1"|bc`
		k3=`echo "$k2+(4*($j-1))"|bc`
		tput cup $a2 $k3
		echo "*"
	done
done

