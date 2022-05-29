#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd, rfile = 0; // 初期化
	int32_t buf[1024]; 
	fd = open(argv[1], O_RDONLY); // ファイルを開く(コマンドライン引数で指定)

	if (fd == -1) //エラー処理
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "No such file.\n");
		}
		else if (errno == EACCES)
		{
			fprintf(stderr, "Access Error.\n");
		}
		else
		{
			fprintf(stderr, "Error No = %u.\n", errno);
		}
		exit(1);
	}
	rfile = read(fd, buf, sizeof(int32_t) * 6); // ファイルを読み込む
	while (rfile > 0)
	{
		write(1, buf, rfile); // ファイルを標準出力に出力
		rfile = read(fd, buf, sizeof(int32_t) * 6);
	}
	close(fd); // ファイルを閉じる
	exit(0);
}