#		*
#	*		*
#*		*		*
fact()
{
	local n=$1
	local x3=1
	for((p1=1;p1<=n;p1++))
	do
		x3=`echo "($x3 * $p1)"|bc`
	done
	echo "$x3"
}
ncr()
{
	local n=$1
	local r=$2
	fn=`fact $n`
	fr=`fact $r`
	local x4=`expr $n-$r`
	fx=`fact $x4`
	x1=`echo "$fn/($fr*$fx)"|bc`
	echo "$x1"
}
echo "enter:"
read n
x=5
y=1
for((i=1;i<=n;i++))
do
	for((j=1;j<=i;j++))
	do
		k2=`echo "(($n-$i)*2)+$y"|bc`
		a2=`echo "($x+$i)-1"|bc`
		k3=`echo "$k2+(4*($j-1))"|bc`
		tput cup $a2 $k3
		i1=`echo "($i-1)"|bc`
		j1=`echo "($j-1)"|bc`
		ncr $i1 $j1
	done
done

		
		


