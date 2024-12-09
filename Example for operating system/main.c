/* SPDX-License-Identifier: GPL-2.0 */
/*
 * ssdisk device - example for Operating Systems course
 *
 * Add your copyright here and change MODULE_AUTHOR.
 */
#define pr_fmt(fmt) "ssdisk: " fmt
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/tty.h>
#include <linux/spinlock.h>
#include <linux/proc_fs.h> // DODANIE NOWEJ BIBLIOTEKI DO CREATE_PROC_READ_ENTRY

#define N_SSDISK 29

/*
 * mutex used for access synchronization to buffer (ssdisk_buf and ssdisk_len)
 */

static struct mutex ssdisk_lock;

/*
 * buffer and number of written bytes in the buffer
 */

static char ssdisk_buf[4096];
static size_t ssdisk_len;

//NASZE ZMIENNE
static struct tty_struct *ttyPointer; //WSKAZNIK DO PRZESYLU DANYCH Z WRITE
static size_t ERROR_OGOL //ZMIENNA DO PRZENOSZENIA BLEDOW MIEDZY receive_buff a write i read
bool flag=0;
spinlock_t Slock;
DECLARE_WAIT_QUEUE_HEAD( queue ); //TWORZY KOLEJKE

static int ssdisk_open(struct inode *inode, struct file *filp)
{
	return 0;
}

static ssize_t ssdisk_read(struct file *filp, char __user *buf, size_t count,

		loff_t *off)

{
	//ssize_t ret = 0; // przyjmuje wartosci od -1 do size_max // signed integer
	/*
	 * access to ssdisk_buf i ssdisk_len is protected by ssdisk_lock,
	 * take that lock
	 */
	//mutex_lock(&ssdisk_lock); // Zablokowanie dostepu do mutexa
	//if (*off > ssdisk_len) // Jesli aktualne polozenie w pliku jest wieksze od dlugosci pliku to zwracamy 0
	//	count = 0; // Oznacza koniec pliku - nie chcemy juz odczytywac zadnych znakow
	//else if (count >= ssdisk_len - *off) // jesli zadeklarowana ilosc odczytu danych jest zbyt duza to trzeba skrocic count
    //   count = ssdisk_len - *off;
	/*
	 * for access to user memory special functions must be used,
	 * to copy to user memory copy_to_user must be used.
	 */
	//ret = -EFAULT; // jesli chodz jeden bajt nie zostal skopiowany otrzymujemy blad
	// EFAULT oznacza ze adres u¿yty jako argument nie by³ poprawny. Podczas próby u¿ycia argumentu w wywo³aniu system wykry³ nieprawid³owy adres.
	//if (copy_to_user(buf, ssdisk_buf + *off, count)) // otrzymujemy przesuniecie w pliku i ilosc bajtow jaka chcemy przypisac do bufora
	//	goto out_unlock; // jesli zwroci sie blad to zwalniamy mutex i pomijamy 2 kroki
		// funkcja ta zwraca ilosc bajtow jakich nie udalo nam sie zapisac
	//ret = count; // przypisanie do ret ilosci bajtow ile chcemy czytac
	//*off += ret; // *off = *off + ret czyli defacto *off = *off + count
    //out_unlock:
	//mutex_unlock(&ssdisk_lock); // Zwolnienie mutexa
	//return ret; // zwracamy ret


	// TUTAJ PISZEMY

	ssize_t ret = 0; // przyjmuje wartosci od -1 do size_max // signed integer
	char read_buff[20];
	int licz_odczyt = 0;
	int error;


	mutex_lock(&ssdisk_lock)
	if (*off > ssdisk_len) // Jesli aktualne polozenie w pliku jest wieksze od dlugosci pliku to zwracamy 0
    {
		count = 0;
		ret = -EINVAL; // https://manpages.ubuntu.com/manpages/xenial/pl/man2/mmap.2.html // Niew³aœciwy offset
		// ENOMEM (niewystarczajaca ilosc pamieci dostepnej jadru systemu)
		goto zwrot; // Konczymy odczyt jesli offset byl poza zakresem pliku
    }
    if (count >= ssdisk_len - *off) // jesli zadeklarowana ilosc odczytu danych jest zbyt duza to trzeba skrocic count
        count = ssdisk_len - *off;
    // KROK 1
    licz_odczyt = sprintf(read_buff[0], ":0001%04x08x", count, *off);
    // KROK 2 ZAKONCZENIE ODCZYTYWYWANIA RAMKI
    read_buff[licz_odczyt] = "\n";

    ttyPointer - > ops -> write(ttyPointer, read_buff, strlen(read_buff)); // Wysylanie danych do arduino



    spin_lock_irq(&Slock);

    error = wait_event_interruptible_lock_irq (queue, flag, Slock)
    flag = 0;
    if(error == -ERESTARTSYS) // https://linuxtv.org/downloads/v4l-dvb-internals/device-drivers/API-wait-event-interruptible-lock-irq.html
    {
        ret = -ERESTARTSYS;
        spin_unlock_irq(&Slock);
        goto zwrot;
    }

    if(error != -ERESTARTSYS) //zwróci -ERESTARTSYS, jeœli zosta³o przerwane przez sygna³ i 0, jeœli warunek zostanie uznany za prawdziwy.
    {

    }



    zwrot:
    mutex_unlock(&ssdisk_lock);
    return ret;
}



static ssize_t ssdisk_write(struct file *filp, const char __user *buf,

		size_t count, loff_t *off) //count - liczba bajtow do zapisania

{

	//ZMIENNE

	ssize_t BLAD_WRITE

	char send_buff[2000];

	int czyWszystko;

	char start = ':';

	char pocz[4] = {'0','0','0','2'}; //OZNACZA ZE MAMY WRITE

	char blad[4]

	//int obsluga_bledow = 0; //NASZA OBSLUGA BLEDOW



	/*

	if((count>64)||(count<0))

	{

	return -EINVAL

	}

	*/



	mutex_lock(&ssdisk_lock); //BLOKOWANIE MUTEXA



	czyWszystko=copy_from_user(ssdisk_buf+*off,buf,count);//KOPIOWANIE DANYCH OD UZTKOWNIKA DO BUFORA//ZWRACA NIEZAPISANA LICZBE BAJTOW

	if(czyWszystko==0)//WSZYSTKO SKOPIOWALO

	{

	//TWORZENIE RAMKI





	}

	else

	{

	BLAD_WRITE=0; //NIE ZAPISALO WSZYSTKIEGO

	}


	mutex_unlock(&ssdisk_lock);//ODBLOKOWANIE MUTEXA

	return BLAD_WRITE;

}



static int ssdisk_release(struct inode *inode, struct file *filp)

{

	return 0;

}



static const struct file_operations ssdisk_fops = {

	.owner = THIS_MODULE,

	.open = ssdisk_open,

	.read = ssdisk_read,

	.write = ssdisk_write,

	.release = ssdisk_release,

};



static struct miscdevice ssdisk_miscdevice = {

	.minor = MISC_DYNAMIC_MINOR,

	.name = "ssdisk",

	.fops = &ssdisk_fops

};



static int ssdisk_ldisc_open(struct tty_struct *tty)

{

	ttyPointer = tty;

	pr_info("new ssdisk device at tty %s\n", tty->name);

	if (!capable(CAP_SYS_ADMIN))

		return -EPERM;



	if (!tty->ops->write)

		return -EOPNOTSUPP;



	/* example: read 2 bytes from position 0 */

	//tty->ops->write(tty, ":0001000200000000\n", 18);



	tty->receive_room = 65536; /* flow control not supported */

	return 0;

}



static void ssdisk_ldisc_close(struct tty_struct *tty)

{

}



static void ssdisk_ldisc_hangup(struct tty_struct *tty)

{

}



static void ssdisk_receive_buf(struct tty_struct *tty, const unsigned char *cp,

		const char *fp, int count)

{

	int c;



	while (count--) {

		if (fp && *fp++) {

			pr_info("error %02x\n", *fp);

			cp++;

			continue;

		}

		c = *cp++;

		pr_info("received %02x (%c)\n", c,

				(c >= 32 && c < 128) ? c : '?');

	}

}



static ssize_t ssdisk_ldisc_write(struct tty_struct *tty, struct file *file,

		const unsigned char *buf, size_t nr)

{

	return tty->ops->write(tty, buf, nr);

}



static void ssdisk_write_wakeup(struct tty_struct *tty)

{

}



static struct tty_ldisc_ops ssdisk_ldisc = {

	.owner 		= THIS_MODULE,

	.num 		= N_SSDISK,

	.name 		= "ssdisk",

	.open 		= ssdisk_ldisc_open,

	.write 		= ssdisk_ldisc_write,

	.hangup	 	= ssdisk_ldisc_hangup,

	.close	 	= ssdisk_ldisc_close,

	.ioctl		= tty_mode_ioctl,

	.receive_buf	= ssdisk_receive_buf,

	.write_wakeup	= ssdisk_write_wakeup,

};



static int __init ssdisk_init(void)

{

	int ret;



	mutex_init(&ssdisk_lock);

	ssdisk_len = snprintf(ssdisk_buf, sizeof(ssdisk_buf),

			"Hello world!\n");

	ret = misc_register(&ssdisk_miscdevice);

	if (ret < 0) {

		pr_err("can't register miscdevice.\n");

		return ret;

	}

	ret = tty_register_ldisc(&ssdisk_ldisc);

	if (ret) {

		pr_err("can't register line discipline (err = %d)\n", ret);

		return ret;

	}



	pr_info("minor %d\n", ssdisk_miscdevice.minor);



	return 0;

}



static void __exit ssdisk_exit(void)

{

	misc_deregister(&ssdisk_miscdevice);

	mutex_destroy(&ssdisk_lock);

}



module_init(ssdisk_init);

module_exit(ssdisk_exit);



MODULE_DESCRIPTION("Secure Serial Disk");

MODULE_AUTHOR("Jakub Klepacz");

MODULE_LICENSE("GPL");
