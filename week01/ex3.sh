mkdir newfolder1
date
sleep 3
mkdir newfolder2
date
sleep 3
ls -ltr / > ~/week1/newfolder1/root.txt
date
sleep 3
ls -ltr ~ > ~/week1/newfolder2/home.txt
echo "content of root.txt"
cat ~/week1/newfolder1/root.txt
echo "content of home.txt"
cat ~/week1/newfolder2/home.txt
echo "items of newfolder1"
ls ~/week1/newfolder1
echo "items of newfolder2"
ls ~/week1/newfolder2
