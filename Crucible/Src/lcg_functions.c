#include "lcg_functions.h"
#include "vl53l0x.h"
#include "motor_B.h"
#include "motor_D.h"
#include "motor.h"
#include "ps2.h"
#include "other_functions.h"
#include "zbw_functions.h"





// 初始化
void car_init(void);
// 一键抓取方块_1  抓取前面几块
void catch_1(void);
// 一键抓取方块_2  抓取最后一块
void catch_2(void);
// 一键释放1_放置低平台
void release_1(void);
// 一键释放2_放置高平台
void release_2(void);






void catch_1(void)
{
	// 校准函数
	jiaozhun();
	// 舵机松
	release_fk();
	// 丝杆低
		// 设置方向 CCW 逆时针，CW顺时针 暂定ACW为丝杆下降
		MSD_StepCounter(ACW);
		// 步进电机由很高下降到低� 10cm 需计算
		MOTER_MOVE(3000,3000,3000,3000);
	// 舵机紧
	catch_fk();
	// 丝杆  低-->很高
		// CW
		MSD_StepCounter(CW);
		MOTER_MOVE(3000,3000,3000,3000);
}

void catch_2(void)
{
	// 校准函数
	jiaozhun();
	// 舵机松
	release_fk();
	// 丝杆低
		// 设置方向 CCW 逆时针，CW顺时针 暂定CCW为丝杆下降
		MSD_StepCounter(ACW);
		// 步进电机由很高下降到低� 10cm 需计算
		MOTER_MOVE(3000,3000,3000,3000);
	// 舵机紧
	catch_fk();
	// 丝杆  低-->中
		// CW
		MSD_StepCounter(CW);
		MOTER_MOVE(3000,3000,3000,3000);
}

void release_1(void)
{
	release_fk();
	open_door();
	
	// 车子向后移动
	move_backward();
	
	close_door();
	// 丝杆 中-->很高
	MSD_StepCounter(CW);
	MOTER_MOVE(3000,3000,3000,3000);
	catch_fk();
	
}

void release_2(void)
{
	release_fk();
	open_door();
	move_backward();
	close_door();
	catch_fk();
}

