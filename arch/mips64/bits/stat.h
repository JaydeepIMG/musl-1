#include <string.h>
#include <bits/alltypes.h>

struct stat {
	dev_t st_dev;
	int pad1[3];
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	unsigned int pad2[2];
	off_t st_size;
	int pad3;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	blksize_t st_blksize;
	unsigned int pad4;
	blkcnt_t st_blocks;
	int pad5[14];
};
