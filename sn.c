//look up serial number
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <sys/fcntl.h>

int main()
{
	struct hd_driveid id;

	int fd = open("/dev/sda11", O_RDONLY|O_NONBLOCK);

	if (fd < 0)
	{
		perror("/dev/hda");
		return 1;
	}
	if (!ioctl(fd, HDIO_GET_IDENTITY, &id))
	{
		printf("serial number = %s\n", id.serial_no);
	}

	return 0;
}
