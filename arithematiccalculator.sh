echo -n "Enter a two number:"
read a
read b
echo "choose an operater"
echo "1.addition"
echo "2.subraction"
echo "3.multiplication"
echo "4.division"
read c
case $c in
1) result=$((a + b)) ;;
2) result=$((a - b)) ;;
3) result=$((a * b)) ;;
4) result=$((a / b)) ;;
*) echo "invalid operator:"
return 1 ;;
esac
echo "result: $result"

