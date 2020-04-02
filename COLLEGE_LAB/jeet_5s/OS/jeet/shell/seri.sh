echo "enter X:"
read x
echo "enter n:"
read n
s=0
t=1
for((i=0;i<2 \* n;i=i+2))
do
	s=`echo "scale = 3;$s + $t"|bc`
	t1=`echo "scale = 3;( $t * $x * $x )"|bc`
	m=`echo "scale = 3;( $i + 1 ) * ( $i + 2 )"|bc`
	t=`echo "scale = 3;( $t1 / $m )"|bc`
done
echo "$s"
