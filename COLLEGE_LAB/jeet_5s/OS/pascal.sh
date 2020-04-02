fact()
{
	x=$1
	if [ $x -eq 0 ]
	then 
		echo 1
	else
		local s=1
		for((i=1;i<=x;i++))
		do
			s=`expr $s \* $i`
		done
		echo $s
	fi
}

echo "Enter the no of rows: "
read r
for((i=0;i<r;i++))
do
	for((j=0;j<=r-i-1;j++))
	do
		echo -n " "
	done
	for((j=0;j<=i;j++))
	do
		x=`expr $i - $j` 
		s=`fact $i` 
		t=`fact $j` 
		z=`fact $x`
		a=`expr $s / \( $t \* $z \)`
		echo -n " $a"
	done
	echo " "
done  

