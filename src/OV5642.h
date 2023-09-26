#ifndef OV5642_H_ 
#define OV5642_H_

#include "OVxxxx_foo.h"
#include "OV5642_register.h"

#define OV5642_DEVICE_WRITE_ADDRESS    0x78
#define OV5642_DEVICE_READ_ADDRESS     0x79

uint8_t Cmos5642_init() {
	uint8_t mmm;

	InitI2C0();
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0xff, 0x01);
    mmm = 0x80;
	if (0 == OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3008, mmm)) {
		return 0;
	}
	delay_ms(1);

	OV5642_set_register();  
	return 1; 
} 

void OV5642_set_register() {
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3103 ,0x93); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3008 ,0x82); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3008 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3017 ,0x7f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3018 ,0xfc); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3810 ,0xc2); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3615 ,0xf0);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3000 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3001 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3002 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3003 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3000 ,0xf8);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3001 ,0x48); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3002 ,0x5c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3003 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3004 ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3005 ,0xff);//
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3006 ,0xff);// 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3007 ,0x07);//
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3011 ,0x08);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3010 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x460c ,0x22); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3815 ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x370d ,0x06); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x370c ,0xa0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3602 ,0xfc);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3612 ,0xff);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3634 ,0xc0);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3613 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3605 ,0x7c);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3621 ,0x09); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3622 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3604 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3603 ,0xa7); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3603 ,0x27); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x4000 ,0x21);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x401d ,0x02);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3600 ,0x54); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3605 ,0x04);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3606 ,0x3f);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3c01 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5000 ,0x4f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5020 ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5181 ,0x79); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5182 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5185 ,0x22); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5197 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5001 ,0xff); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5500 ,0x0a); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5504 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5505 ,0x7f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5080 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x300e ,0x18);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x4610 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x471d ,0x05); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x4708 ,0x06); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3710 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3632 ,0x41); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3702 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3620 ,0x37); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3631 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3808 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3809 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380a ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380b ,0xe0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380e ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380f ,0xd0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x501f ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5000 ,0x4f);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x4300 ,0x30);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3503 ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3501 ,0x73);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3502 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350b ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3503 ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3824 ,0x11);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3501 ,0x1e);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3502 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350b ,0x7f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380c ,0x0c);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380d ,0x80);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380e ,0x03);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380f ,0xe8);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0d ,0x04);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0e ,0x03); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3818 ,0xc1); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3705 ,0xdb); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x370a ,0x81);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3801 ,0x80);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3621 ,0xc7);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3801 ,0x50); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3803 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3827 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3810 ,0xc0);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3804 ,0x05);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3805 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5682 ,0x05); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5683 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3806 ,0x03); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3807 ,0xc0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5686 ,0x03); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5687 ,0xc0);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a00 ,0x78); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1a ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a13 ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a18 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a19 ,0x7c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a08 ,0x12); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a09 ,0xc0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0a ,0x0f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0b ,0xa0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3004 ,0xff);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350c ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350d ,0xd0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3500 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3501 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3502 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350a ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x350b ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3503 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528a ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528b ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528c ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528d ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528e ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528f ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5290 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5292 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5293 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5294 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5295 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5296 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5297 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5298 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5299 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529a ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529b ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529c ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529d ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529e ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529f ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0f ,0x3c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a10 ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1b ,0x3c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1e ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a11 ,0x70); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1f ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3030 ,0x0b); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a02 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a03 ,0x7d); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a04 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a14 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a15 ,0x7d); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a16 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a00 ,0x7c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a08 ,0x09); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a09 ,0x60); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0a ,0x07); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0b ,0xd0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0d ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0e ,0x06); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5193 ,0x70); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3620 ,0x57); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3703 ,0x98); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3704 ,0x1c);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x589b ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x589a ,0xc5); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528a ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528b ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528c ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528d ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528e ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x528f ,0x28); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5290 ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5292 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5293 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5294 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5295 ,0x02);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5296 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5297 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5298 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5299 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529a ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529b ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529c ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529d ,0x28); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529e ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x529f ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5282 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5300 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5301 ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5302 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5303 ,0x7c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x530c ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x530d ,0x0c);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x530e ,0x20);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x530f ,0x80);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5310 ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5311 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5308 ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5309 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5304 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5305 ,0x30); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5306 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5307 ,0x80); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5314 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5315 ,0x20);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5319 ,0x30);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5316 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5317 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5318 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5380 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5381 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5382 ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5383 ,0x4e); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5384 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5385 ,0x0f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5386 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5387 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5388 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5389 ,0x15); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538a ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538b ,0x31);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538c ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538d ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538e ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x538f ,0x0f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5390 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5391 ,0xab); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5392 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5393 ,0xa2); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5394 ,0x08); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5480 ,0x14); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5481 ,0x21); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5482 ,0x36); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5483 ,0x57); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5484 ,0x65);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5485 ,0x71); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5486 ,0x7d); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5487 ,0x87); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5488 ,0x91); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5489 ,0x9a); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548a ,0xaa); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548b ,0xb8); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548c ,0xcd); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548d ,0xdd); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548e ,0xea); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x548f ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5490 ,0x05); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5491 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5492 ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5493 ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5494 ,0x03); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5495 ,0x60); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5496 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5497 ,0xb8); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5498 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5499 ,0x86);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549a ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549b ,0x5b); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549c ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549d ,0x3b);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549e ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x549f ,0x1c);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a0 ,0x02);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a1 ,0x04);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a2 ,0x01);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a3 ,0xed);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a4 ,0x01);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a5 ,0xc5);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a6 ,0x01);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a7 ,0xa5);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a8 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54a9 ,0x6c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54aa ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54ab ,0x41); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54ac ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54ad ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54ae ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x54af ,0x16); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3406 ,0x00); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5192 ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5191 ,0xf8); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5193 ,0x70); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5194 ,0xf0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5195 ,0xf0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518d ,0x3d); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518f ,0x54); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518e ,0x3d);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5190 ,0x54); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518b ,0xc0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518c ,0xbd); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5187 ,0x18); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5188 ,0x18); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5189 ,0x6e); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518a ,0x68); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5186 ,0x1c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5181 ,0x50); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5184 ,0x25);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5182 ,0x11); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5183 ,0x14); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5184 ,0x25);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5185 ,0x24); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5025 ,0x82);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0f ,0x7e); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a10 ,0x72);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1b ,0x80);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1e ,0x70);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a11 ,0xd0); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1f ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5583 ,0x40);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5584 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5580 ,0x02); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3633 ,0x07);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3702 ,0x10); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3703 ,0xb2); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3704 ,0x18);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x370b ,0x40);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x370d ,0x02);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3620 ,0x52);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3808 ,0x01);

	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3809 ,0x40);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380a ,0x00); 

	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380b ,0xf0); 

	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a00 ,0x78);

	//
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3818,0x81); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3621,0xe7); 

	//Contrast +1 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5001 ,0xff);  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5580 ,0x04);  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5587 ,0x24); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5588 ,0x24); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x558a ,0x00);  
	///Saturation 0 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5001 ,0xff);  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5583 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5584 ,0x40); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5580 ,0x02);  
	//Brightness +1 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5001 ,0xff);  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5589 ,0x10);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5580 ,0x04);  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x558a ,0x00); 
	//Advanced AWB  
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3406 ,0x0 );
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5192 ,0x04); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5191 ,0xf8); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518d ,0x26);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518f ,0x42);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518e ,0x2b); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5190 ,0x42); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518b ,0xd0);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518c ,0xbd);                            
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5187 ,0x18);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5188 ,0x18);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5189 ,0x56); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x518a ,0x5c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5186 ,0x1c); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5181 ,0x50); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5184 ,0x20);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5182 ,0x11);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5183 ,0x0 );

	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a0f ,0x58); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a10 ,0x50); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a11 ,0x91); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1b ,0x58) ;
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1e ,0x50); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3a1f ,0x20); 

	//hue +30 degree      
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5580 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5581 ,0x6f); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5582 ,0x20); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x558a ,0x01);
	////RGB565
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x501e ,0x2a);  // ?
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x5002 ,0xf8);  // ?
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x501f ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x4300 ,0x61);  // ? 
	//qvga out
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3808 ,0x01); 
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x3809 ,0x40);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380a ,0x00);
	OVxxxx_WriteReg(OV5642_DEVICE_WRITE_ADDRESS, 0x380b ,0xf0); 
}

#endif  // OV5642_H_
