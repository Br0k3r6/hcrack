hcrack:
	chmod +x hcrack.py;
	gcc src/hash/md5.c -lssl -lcrypto -o lib/hash/md5/md5 --no-warnings;
	chmod +x lib/hash/md5/md5
	g++ parser.cpp parser.hpp -o parser.out
	chmod +x parser.out
	gcc src/hash/md4.c -lssl -lcrypto -o lib/hash/md4/md4 --no-warnings;
	chmod +x lib/hash/md4/md4
	gcc src/hash/sha256.c -lssl -lcrypto -o lib/hash/sha256/sha256 --no-warnings;
	chmod +x lib/hash/sha256/sha256
	gcc src/hash/sha512.c -lssl -lcrypto -o lib/hash/sha512/sha512 --no-warnings;
	chmod +x lib/hash/sha512/sha512
