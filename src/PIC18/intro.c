#include <system.h>
#include "intro.h"
#include "gpu_pic.h"
#include "spu_pic.h"

void cls(char color)
{
	//clear screen and also check for exiting
	Sprite me;
		me.image.lines = 24;
		me.image.width = 160;
		me.position.x = 0;
		me.position.y = 0;
		me.alpha = 0;
		me.visible = 1;
	char i;
	
	if (color == 0)
		me.image.address = 0x000B6F80;
	else if (color == 1)
		me.image.address = 0x000B7E80;
	else if (color == 2)
		me.image.address = 0x000B8D80;
	else if (color == 3)
		me.image.address = 0x000B9C80;
	for ( i = 0; i < 10; i++)
	{
		drawsprite(me);
		me.position.y += 24;
	}
	return;
}

void fadeinout(void)
{
	char i;
	//fade in and out at the end of bootup
	for ( i = 0; i < 4; i++)
	{
		cls (i);
		delay_ms(50);
	}
	delay_ms(250);
	delay_ms(250);
	for ( i = 0; i < 4; i++)
	{
		cls (3-i);
		delay_ms(50);
	}
	return;
}

#pragma OPTIMIZE "0"
void scene1(void)
{
	char i = 0;
	char j = 0;
		
	//initalize graphics to original settings
	
	Sprite near_future;
		near_future.image.address = 0x00025800;
		near_future.image.lines = 0x0B;
		near_future.image.width = 0xA0;
		near_future.position.x = 0;
		near_future.position.y = 63;
		near_future.alpha = 0;
		near_future.visible = 1;

	Sprite eye_anim;
		eye_anim.image.address = 0x00026CA0;
		eye_anim.image.lines = 0x1B;
		eye_anim.image.width = 0x1F;
		eye_anim.position.x = 14;
		eye_anim.position.y = 135;
		eye_anim.alpha = 0;
		eye_anim.visible = 1;
	
	Sprite eye_mask;
		eye_mask.image.address = 0x0001C200;
		eye_mask.image.lines = 0x1B;
		eye_mask.image.width = 0x1F;
		eye_mask.position.x = 14;
		eye_mask.position.y = 135;
		eye_mask.alpha = 0;
		eye_mask.visible = 1;
			
	Sprite compass;
		compass.image.address = 0x00029A40;
		compass.image.lines = 0x06;
		compass.image.width = 0x2D;
		compass.position.x = 51;
		compass.position.y = 134;
		compass.alpha = 0;
		compass.visible = 1;

	Sprite lines;
		lines.image.address = 0x00029E00;
		lines.image.lines = 0x1A;
		lines.image.width = 0x4F;
		lines.position.x = 73;
		lines.position.y = 76;
		lines.alpha = 0;
		lines.visible = 1;

	Sprite bars;
		bars.image.address = 0x0002AE94;
		bars.image.lines = 15;
		bars.image.width = 0x2F;
		bars.position.x = 10;
		bars.position.y = 81;
		bars.alpha = 0;
		bars.visible = 1;

	Sprite outline;
		outline.image.address = 0x00027D80;
		outline.image.lines = 46;
		outline.image.width = 43;
		outline.position.x = 27;
		outline.position.y = 130;
		outline.alpha = 1;
		outline.visible = 1;

	//fade in introduction text
	cls(0);
	delay_s(1);
	playmusic (1);
	delay_ms(255);
	delay_ms(255);
	drawsprite(near_future);
	delay_ms(255);
	near_future.image.address = 0X00025EE0;
	cls(0);
	drawsprite(near_future);
	delay_ms(255);
	near_future.image.address = 0X000265C0;
	cls(0);
	drawsprite(near_future);
	delay_s(2);
	//black screen - dramatic pause
	cls(0);
	delay_s(2);
	//draw eye open animation
	for (i = 0; i < 5; i++)
	{
		drawsprite(eye_mask);
		drawsprite(eye_anim);
		eye_anim.image.address += 0x00000020;
		delay_ms(100);
	}
	//draw and animate compass
	j = 30;
	for ( i = 0; i < 5; i++)//slow down
	{
		drawsprite(compass);//1
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//2
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//3
		compass.image.address -= 0x0000005C;	
		delay_ms(j);
		j+= 15;
	}
	j=20;
	for ( i = 0; i < 5; i++)//reverse
	{
		compass.image.address += 0x0000005C;
		drawsprite(compass);//3
		compass.image.address -= 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//2
		compass.image.address -= 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//1
		delay_ms(j);
		j+= 15;
	}
	j=150;
	for ( i = 0; i < 3; i++)//speed up
	{
		drawsprite(compass);//1
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//2
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//3
		compass.image.address -= 0x0000005C;	
		delay_ms(j);
		j-= 60;
	}
	drawsprite (lines);
	drawsprite (bars);

	j=10;
	for ( i = 0; i < 2; i++)//slow down
	{
		drawsprite(compass);
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//2
		compass.image.address += 0x0000002E;
		delay_ms(j);
		drawsprite(compass);//3
		compass.image.address -= 0x0000005C;	
		delay_ms(j);
		j+= 40;
	}

	lines.image.address = 0x00029E50;
	lines.image.width = 0x4B;
	bars.image.address += 0x00000960;
	bars.image.width = 0x35;
	drawsprite (lines);
	drawsprite (bars);
	
	drawsprite(compass);
	compass.image.address += 0x0000002E;
	delay_ms(j);
	drawsprite(compass);//2
	compass.image.address += 0x0000002E;
	delay_ms(j);
	drawsprite(compass);//3
	compass.image.address -= 0x0000005C;	
	delay_ms(j);
	j+= 40;

	lines.image.address = 0x0002AE40;
	lines.image.width = 0x53;
	bars.image.address += 0x0000960;
	drawsprite (lines);
	drawsprite (bars);
	
	//last compass animation
	//drawsprite (north);
	//drawsprite (south);
	//drawsprite (east);
	//drawsprite (west);

	drawsprite(compass);
	compass.image.address += 0x0000002E;
	delay_ms(j);
	drawsprite(compass);//2
	compass.image.address += 0x0000002E;
	delay_ms(j);
	drawsprite(compass);//3
	compass.image.address -= 0x0000005C;	
	delay_ms(j);
	drawsprite(compass);//1
	
	lines.image.address = 0x0002BE80;
	bars.image.address += 0x00000961;
	bars.image.width = 0x36;
	drawsprite (lines);
	drawsprite (bars);
	delay_ms(200);

	lines.image.address = 0x0002CEC0;
	lines.image.lines = 32;
	lines.image.width = 84;
	lines.position.x = 72;
	lines.position.y = 75;
	bars.image.address += 0x00000960;
	drawsprite (bars);	
	drawsprite (lines);
	delay_ms(50);
	bars.image.address = 0x000713E0;
	bars.image.lines = 21;
	bars.image.width = 62;
	bars.position.x = 4;
	bars.position.y = 80;
	drawsprite (bars);
	drawsprite (lines);
	
	//glitch stuff up
	for (i = 0; i < 50; i++)
	{
		bars.image.address = 0x000713E0;
		lines.image.address = 0x000821E0;
		drawsprite(bars);
		drawsprite (lines);
		delay_ms(5);
		bars.image.address = 0x000706C0;
		lines.image.address = 0x0002CEC0;
		drawsprite(bars);
		drawsprite (lines);
		delay_ms(5);			
	}	

	//draw overlay
	
	drawsprite (outline);		

	for (i = 0; i < 30; i++)
	{
		bars.image.address = 0x000713E0;
		lines.image.address = 0x000821E0;
		drawsprite(bars);
		drawsprite (lines);
		delay_ms(5);
		bars.image.address = 0x000706C0;
		lines.image.address = 0x0002CEC0;
		drawsprite(bars);
		drawsprite (lines);
		delay_ms(5);			
	}		

	//draw eye close animation with overlay
	eye_anim.image.address = 0x00026D20;
	for (i = 0; i < 5; i++)
	{
		drawsprite(eye_mask);			
		drawsprite(eye_anim);
		drawsprite(outline);
		eye_anim.image.address -= 0x00000020;
		delay_ms(50);
	}
	//draw eye open with overlay
	eye_anim.image.address = 0x00026CA0;
	for (i = 0; i < 5; i++)
	{
		drawsprite(eye_mask);
		drawsprite(eye_anim);
		drawsprite(outline);
		eye_anim.image.address += 0x00000020;
		delay_ms(50);
	}

	delay_ms(255);
	//draw rest of overlay
	drawsprite(eye_mask);
	outline.position.x = 24;
	outline.image.address = 0x00027DAB;
	outline.image.width = 46;
	drawsprite(outline);
	drawsprite(compass);
	delay_ms(200);
	outline.image.address = 0x00027DD9;
	outline.image.width = 60;
	drawsprite(outline);
	drawsprite(compass);
	delay_s(2);
	
	return;
}
void scene2(void)
{
	char i = 0;
	char j = 0;
	
	//initalize graphics to original settings
	
	Sprite pilot;
		pilot.image.address = 0x000AB180;//0x000A4740;
		pilot.image.lines = 170;
		pilot.image.width = 77;
		pilot.position.x = 20;
		pilot.position.y = 39;
		pilot.alpha = 1;
		pilot.visible = 1;
	
	Sprite screen0;
		screen0.image.address = 0x000A86AD;
		screen0.image.lines = 69;
		screen0.image.width = 40;
		screen0.position.x = 72;
		screen0.position.y = 71;
		screen0.alpha = 1;
		screen0.visible = 1;
		
	Sprite screen1;
		screen1.image.address = 0x000A4F0D;
		screen1.image.lines = 89;
		screen1.image.width = 59;
		screen1.position.x = 72;
		screen1.position.y = 59;
		screen1.alpha = 1;
		screen1.visible = 1;
	
	Sprite screen2;
		screen2.image.address = 0x0009E5C0;
		screen2.image.lines = 156;
		screen2.image.width = 57;
		screen2.position.x = 49;
		screen2.position.y = 25;
		screen2.alpha = 1;
		screen2.visible = 1;
		
	Sprite screen3;
		screen3.image.address = 0x0009E5F9;
		screen3.image.lines = 156;
		screen3.image.width = 38;
		screen3.position.x = 106;
		screen3.position.y = 25;
		screen3.alpha = 1;
		screen3.visible = 1;
		
	Sprite screen4;
		screen4.image.address = 0x0009A060;
		screen4.image.lines = 111;
		screen4.image.width = 40;
		screen4.position.x = 13;
		screen4.position.y = 3;
		screen4.alpha = 1;
		screen4.visible = 1;
	
	Sprite screen5;
		screen5.image.address = 0x0009A095;
		screen5.image.lines = 111;
		screen5.image.width = 21;
		screen5.position.x = 67;
		screen5.position.y = 3;
		screen5.alpha = 1;
		screen5.visible = 1;
	
	Sprite screen6;
		screen6.image.address = 0x00099EEB;
		screen6.image.lines = 17;
		screen6.image.width = 17;
		screen6.position.x = 120;
		screen6.position.y = 2;
		screen6.alpha = 1;
		screen6.visible = 1;
		
	Sprite screen7;
		screen7.image.address = 0x000AA575;
		screen7.image.lines = 20;
		screen7.image.width = 16;
		screen7.position.x = 143;
		screen7.position.y = 188;
		screen7.alpha = 1;
		screen7.visible = 1;
		
	Sprite boot0;
		boot0.image.address = 0x000A478D;
		boot0.image.lines = 12;
		boot0.image.width = 59;
		boot0.position.x = 6;
		boot0.position.y = 15;
		boot0.alpha = 1;
		boot0.visible = 1;
		
	Sprite boot1;
		boot1.image.address = 0x000A0EBF;
		boot1.image.lines = 9;
		boot1.image.width = 65;
		boot1.position.x = 6;
		boot1.position.y = 29;
		boot1.alpha = 1;
		boot1.visible = 1;
		
	Sprite boot2;
		boot2.image.address = 0x000A145F;
		boot2.image.lines = 9;
		boot2.image.width = 65;
		boot2.position.x = 6;
		boot2.position.y = 44;
		boot2.alpha = 1;
		boot2.visible = 1;
		
	Sprite boot3;
		boot3.image.address = 0x000A19FF;
		boot3.image.lines = 9;
		boot3.image.width = 26;
		boot3.position.x = 6;
		boot3.position.y = 58;
		boot3.alpha = 1;
		boot3.visible = 1;

	Sprite boot4;
		boot4.image.address = 0x00099AC0;
		boot4.image.lines = 9;
		boot4.image.width = 60;
		boot4.position.x = 6;
		boot4.position.y = 73;
		boot4.alpha = 1;
		boot4.visible = 1;
	
	Sprite boot5;
		boot5.image.address = 0x00099AFC;
		boot5.image.lines = 9;
		boot5.image.width = 60;
		boot5.position.x = 66;
		boot5.position.y = 73;
		boot5.alpha = 1;
		boot5.visible = 1;
		
	cls(0);
	delay_s(1);
	drawsprite(pilot);
	delay_ms(200);
	drawsprite(screen0);
	//flash newest screen
	for (i = 0; i < 10; i++)
	{
		cls(0);
		drawsprite(pilot);
		delay_ms(25);
		drawsprite(screen0);
		delay_ms(25);
	}	
	drawsprite(screen1);	
	for (i = 0; i < 10; i++)
	{
		cls(0);
		drawsprite(pilot);
		drawsprite(screen0);
		delay_ms(25);
		drawsprite(screen1);
		delay_ms(25);
	}	
	
	drawsprite(screen2);
	drawsprite(screen3);		
	for (i = 0; i < 10; i++)
	{
		cls(0);
		drawsprite(pilot);
		drawsprite(screen0);
		drawsprite(screen1);
		delay_ms(25);
		drawsprite(screen2);
		drawsprite(screen3);
		delay_ms(25);
		if (i == 3)
			pilot.image.address = 0x000AB1CD;
	}	

	delay_ms(255);
	drawsprite(screen4);
	drawsprite(screen5);
	drawsprite(screen6);
	drawsprite(screen7);
	for (i = 0; i < 10; i++)
	{
		cls(0);
		drawsprite(pilot);
		drawsprite(screen0);
		drawsprite(screen1);
		drawsprite(screen2);
		drawsprite(screen3);
		delay_ms(25);
		drawsprite(screen4);
		drawsprite(screen5);
		drawsprite(screen6);
		drawsprite(screen7);
		delay_ms(25);
		if (i == 7)
			pilot.image.address = 0x000A4740;
		
	}	

	delay_s (1);
	drawsprite(boot0);
	delay_ms(255);
	delay_ms(255);
	drawsprite(boot1);
	delay_ms(255);
	delay_ms(255);
	delay_ms(255);
	drawsprite(boot2);
	delay_s(2);
	drawsprite(boot3);
	delay_ms(255);
	drawsprite(boot4);
	drawsprite(boot5);
	delay_s(3);
	return;
}

#pragma OPTIMIZE "0"	// yea, cool, don't listen to us
void scene3(void)
{
	char i = 0;
	char j = 0;

	Sprite cannon1;
		cannon1.image.address = 0x0005308A;
		cannon1.image.lines = 186;
		cannon1.image.width = 44;
		cannon1.position.x = 10;
		cannon1.position.y = 40;
		cannon1.alpha = 0;
		cannon1.visible = 1;
		
	Sprite cannon2;
		cannon2.image.address = 0x0005A4CA;
		cannon2.image.lines = 186;
		cannon2.image.width = 44;
		cannon2.position.x = 10;
		cannon2.position.y = 40;
		cannon2.alpha = 0;
		cannon2.visible = 1;
		
	Sprite cannon3;
		cannon3.image.address = 0x00064280;
		cannon3.image.lines = 186;
		cannon3.image.width = 44;
		cannon3.position.x = 10;
		cannon3.position.y = 40;
		cannon3.alpha = 0;
		cannon3.visible = 1;

	Sprite credit1;
		credit1.image.address = 0x000B1BC0;
		credit1.image.lines = 45;
		credit1.image.width = 60;
		credit1.position.x = 65;
		credit1.position.y = 80;
		credit1.alpha = 1;
		credit1.visible = 1;
		
	Sprite credit2;
		credit2.image.address = 0x000B1BFC;
		credit2.image.lines = 45;
		credit2.image.width = 60;
		credit2.position.x = 65;
		credit2.position.y = 140;
		credit2.alpha = 1;
		credit2.visible = 1;
				
	Sprite credit3;
		credit3.image.address = 0x000B37E0;
		credit3.image.lines = 45;
		credit3.image.width = 60;
		credit3.position.x = 10;
		credit3.position.y = 120;
		credit3.alpha = 1;
		credit3.visible = 1;
	
	Sprite credit4;
		credit4.image.address = 0x000B381C;
		credit4.image.lines = 45;
		credit4.image.width = 60;
		credit4.position.x = 10;
		credit4.position.y = 180;
		credit4.alpha = 1;
		credit4.visible = 1;
		
	Sprite credit5;
		credit5.image.address = 0x000B5400;
		credit5.image.lines = 45;
		credit5.image.width = 60;
		credit5.position.x = 99;
		credit5.position.y = 120;
		credit5.alpha = 1;
		credit5.visible = 1;
	
	Sprite credit6;
		credit6.image.address = 0x000B543C;
		credit6.image.lines = 45;
		credit6.image.width = 60;
		credit6.position.x = 99;
		credit6.position.y = 180;
		credit6.alpha = 1;
		credit6.visible = 1;
		
	Sprite grid;
		grid.image.address = 0x00052F80;
		grid.image.lines = 150;
		grid.image.width = 105;
		grid.position.x = 40;
		grid.position.y = 0;
		grid.alpha = 0;
		grid.visible = 1;
	
	Sprite plane_1;
		plane_1.image.address = 0x00064221;
		plane_1.image.lines = 150;
		plane_1.image.width = 49;
		plane_1.position.x = 50;
		plane_1.position.y = 0;
		plane_1.alpha = 1;
		plane_1.visible = 1;
		
	Sprite plane_2;
		plane_2.image.address = 0x00064252;
		plane_2.image.lines = 150;
		plane_2.image.width = 46;
		plane_2.position.x = 99;
		plane_2.position.y = 0;
		plane_2.alpha = 1;
		plane_2.visible = 1;
	
	Sprite tech_1;
		tech_1.image.address = 0x000717E1;
		tech_1.image.lines = 150;
		tech_1.image.width = 49;
		tech_1.position.x = 45;
		tech_1.position.y = 00;
		tech_1.alpha = 1;
		tech_1.visible = 1;
		
	Sprite tech_2;
		tech_2.image.address = 0x00071812;
		tech_2.image.lines = 150;
		tech_2.image.width = 46;
		tech_2.position.x = 94;
		tech_2.position.y = 00;
		tech_2.alpha = 1;
		tech_2.visible = 1;
	
	cls(0);

	//draw cannon and some credits
	//leadin animations
	drawsprite (cannon1);
	delay_ms(200);
	
	drawsprite (credit1);
	drawsprite (credit2);
	//speed up
	for (i = 0; i < 25; i++)
	{
		drawsprite(cannon2);
		delay_ms(125 - (i * 4));
		drawsprite(cannon3);
		delay_ms(125 - (i * 4));
	}
	//slow down
	for (i = 0; i < 25; i++)
	{
		drawsprite(cannon2);
		delay_ms(25 + (i * 4));
		drawsprite(cannon3);
		delay_ms(25 + (i * 4));
	}
	//leadout animations
	delay_ms(125);
	drawsprite(cannon2);
	delay_ms(200);
	drawsprite (cannon1);
	delay_ms(200);
	cls(0);
	delay_ms(255);
	
	//scroll plane up
	for (i = 0; i < 70; i++)
	{
		drawsprite (grid);
		drawsprite (plane_1);
		drawsprite (plane_2);
		drawsprite (credit3);
		drawsprite (credit4);
		grid.image.address += 160;
		plane_1.image.address += 160;
		plane_2.image.address += 160;
		tech_1.image.address += 160;
		tech_2.image.address += 160;
		delay_ms(130);
	}
	delay_ms(255);


	//move screen left	
	while(grid.position.x > 0)
	{
		grid.position.x -= 1;
		tech_1.position.x -= 1;
		tech_2.position.x -= 1;
		plane_1.position.x -= 1;
		plane_2.position.x -= 1;

		cls(0);	
		drawsprite (grid);
		drawsprite (plane_1);
		drawsprite (plane_2);
		delay_ms(20);
	}
	
	//scroll plane up with overlay
	for (i = 0; i < 70; i++)
	{
		drawsprite (grid);
		drawsprite (plane_1);
		drawsprite (plane_2);
		drawsprite (tech_1);
		drawsprite (tech_2);
		drawsprite (credit5);
		drawsprite (credit6);
		
		grid.image.address += 160;
		plane_1.image.address += 160;
		plane_2.image.address += 160;
		tech_1.image.address += 160;
		tech_2.image.address += 160;
		delay_ms(130);
	}

	cls(0);
	delay_s(1);
}


void scene4(void)
{
	char i = 0;
	char j = 0;
	char front_buffer = 0;

	Sprite skyline;
		skyline.image.address = 0x00090510;
		skyline.image.lines = 240;
		skyline.image.width = 0;
		skyline.position.x = 80;
		skyline.position.y = 0;
		skyline.alpha = 0;
		skyline.visible = 1;
	
	Sprite engine;
		engine.image.address = 0x0008AD14;
		engine.image.lines = 18;
		engine.image.width = 29;
		engine.position.x = 66;
		engine.position.y = 150;
		engine.alpha = 1;
		engine.visible = 1;
		
	Sprite plane_1;
		plane_1.image.address = 0x0008B7E0;
		plane_1.image.lines = 40;
		plane_1.image.width = 40;
		plane_1.position.x = 0;
		plane_1.position.y = 200;
		plane_1.alpha = 1;
		plane_1.visible = 1;
		
	Sprite plane_2;
		plane_2.image.address = 0x0008B808;
		plane_2.image.lines = 40; 
		plane_2.image.width = 40;
		plane_2.position.x = 40;
		plane_2.position.y = 200;
		plane_2.alpha = 1;
		plane_2.visible = 1;
	
	Sprite plane_3;
		plane_3.image.address = 0x0008B830;
		plane_3.image.lines = 40;
		plane_3.image.width = 40;
		plane_3.position.x = 80;
		plane_3.position.y = 200;
		plane_3.alpha = 1;
		plane_3.visible = 1;
	
	Sprite plane_4;
		plane_4.image.address = 0x0008B858;
		plane_4.image.lines = 40; //123;
		plane_4.image.width = 40;
		plane_4.position.x = 120;
		plane_4.position.y = 200;
		plane_4.alpha = 1;
		plane_4.visible = 1;
		
	cls(0);
	
	//this part is done in double buffer mode
	set_drawmode(1);
	//flush video buffers
	cls(0);
	flip_buffer(front_buffer);
	for (i = 0; i <81 ; i++)
	{
		cls(0);
		drawsprite (skyline);
		drawsprite (plane_1);
		drawsprite (plane_2);
		drawsprite (plane_3);
		drawsprite (plane_4);
		flip_buffer(front_buffer);
		//do some slide fx here
		skyline.image.width +=2;
		skyline.image.address --;
		skyline.position.x --;
	
		plane_1.position.y -= 1;
		plane_2.position.y -= 1;
		plane_3.position.y -= 1;
		plane_4.position.y -= 1;
		plane_1.image.lines ++;
		plane_2.image.lines ++;	
		plane_3.image.lines ++;
		plane_4.image.lines ++;
		
		delay_ms(20 + i);
	}
	set_drawmode(0);
	delay_s(2);
	plane_2.position.y ++;
	plane_3.position.y ++;
	for ( i = 0; i < 5; i++)
	{
		drawsprite (plane_2);
		drawsprite (plane_3);
		drawsprite(engine);
		delay_ms(255 - (i * 16));
		engine.image.address -= 29;
	}
	delay_ms(255);
}

void scene5(void)
{
	char i = 0;
	char j = 0;
	unsigned long takeoff_addr[8] = 
	{
		0x0002E720,
		0x000332C0,
		0x00037E60,
		0x0003CA00,
		0x00040BA0,
		0x00044D40,
		0x00049840,
		0x0004E3E0
	};
	char takeoff_lines[8] =
	{
		121,
		121,
		121,
		105,
		105,
		120,
		120,
		121
	};
	Sprite takeoff;
		takeoff.image.address = takeoff_addr[0];
		takeoff.image.lines = takeoff_lines[0];
		takeoff.image.width = 160;
		takeoff.position.x = 0;
		takeoff.position.y = 49;
		takeoff.alpha = 0;
		takeoff.visible = 1;
		
	cls(0);
	
	//accelerate plane
	for (i = 0; i < 5 ; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			drawsprite (takeoff);
			takeoff.image.address = takeoff_addr[j];
			takeoff.image.lines = takeoff_lines[j];
			delay_ms (60 - (i * 4));
		}
	}

	//max speed
	for (i = 0; i < 5 ; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			drawsprite (takeoff);
			takeoff.image.address = takeoff_addr[j];
			takeoff.image.lines = takeoff_lines[j];
			delay_ms(40);
		}
	}
	cls(0);
}

void scene6(void)
{
	char i = 0;
	char j = 0;
	Sprite reflect;
		reflect.image.address = 0x0E1140;
		reflect.image.lines = 90;
		reflect.image.width = 160;
		reflect.position.x = 0;
		reflect.position.y = 80;
		reflect.alpha = 0;
		reflect.visible = 1;
	cls(0);
	for (i = 0; i < 5 ; i++)
	{
		for ( j = 0; j < 10; j++)
		{
			drawsprite (reflect);
			reflect.image.address += 0x3840;
			delay_ms(80);

		}
		//reset thingy to beginning
		reflect.image.address = 0x0E1140;
	}
	cls(0);
}

void bootup(void)
{
	char i = 0;
	char j = 0;

	Sprite frame;
		frame.image.address = 0x00376800;
		frame.image.lines = 160;
		frame.image.width = 79;
		frame.position.x = 40;
		frame.position.y = 40;
		frame.alpha = 0;
		frame.visible = 1;
	
	cls(0);
		
	delay_ms(200);

	//play boot movie
	for (i = 0; i <  21; i++)
	{
		//show 'left' frame
		drawsprite (frame);
		if (i == 0)
		{
			delay_ms(250);
			delay_ms(250);
		}
		
		//show 'right' frame
		if (i > 18)
			delay_ms(100);
		else
			delay_ms(60);
		frame.image.address += 80;
		drawsprite (frame);
		if (i > 18)
			delay_ms(100);
		else
			delay_ms(60);
		//skip down to next two frames
		frame.image.address += 25520;	
	}
	fadeinout();
}