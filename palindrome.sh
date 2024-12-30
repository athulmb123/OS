echo -n "Enter a number : "
read n
copy=$n
rev=0
while [ $n -gt 0 ]; do
	digit=$((n % 10))
	rev=$((rev * 10 + digit))
	n=$((n / 10))
done
echo "The reverse of the number is : $rev"
if [ $copy -eq $rev ]; then
	echo "The number is a palindrome."
else
	echo "The number is not a palindrome."
fi 

