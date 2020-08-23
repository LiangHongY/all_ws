#include<iostream>
#include<fstream>
#include<string>
#include<regex>

using namespace std;

//class test
//{
//public:
//	string m_name;
//	string m_mean;
//};
  
int main()
{
	//test test1;
	string test2[6][2];
	ifstream ifs1;

	//打开文件2并且判断是否打开成功
	ifs1.open("test2.txt", ios::in);
	if (!ifs1.is_open())
	{
		cout << "文件1打开失败" << endl;
		return 0;
	}

	string buf2;

	while (getline(ifs1, buf2))
	{
		//cout << buf << endl;
		//regex pattern("(^Depthcamera_right_rpy_r_delta.*): (.*)$");//名称处不包含：


		//regex pattern4("(^Depthcamera_right_rpy_r_delta:.*) (.*)$");//名称处包含：

		//smatch results4;
		//if (regex_match(buf2, results4, pattern4)) {
		//	//for (auto it = results.begin(); it != results.end(); ++it)
		//	//{
		//	//	cout << *it << endl;

		//	//}
		//	auto it = results4.begin();
		//	it != results4.end();
		//	++it;
		//	//test1.m_name = *it;
		//	//cout << *it << endl;
		//	//cout << test1.m_name << endl;
		//	test2[3][0] = *it;
		//	//cout << test2[3][0] << endl;

		//	++it;
		//	//test1.m_mean = *it;
		//	//cout << test1.m_mean << endl;
		//	//cout << *it << endl;
		//	test2[3][1] = *it;
		//	//cout << test2[3][1] << endl;
		//}
		////else {
		////	cout << "匹配失败：" << buf << endl;
		////}

		regex pattern1("(^Depthcamera_right_xyz_x_delta:.*) (.*)$");
		smatch results1;
		if (regex_match(buf2, results1, pattern1)) {
			auto it = results1.begin();
			it != results1.end();
			++it;
			test2[0][0] = *it;

			++it;
			test2[0][1] = *it;
		}

		regex pattern2("(^Depthcamera_right_xyz_y_delta:.*) (.*)$");
		smatch results2;
		if (regex_match(buf2, results2, pattern2)) {
			auto it = results2.begin();
			it != results2.end();
			++it;
			test2[1][0] = *it;

			++it;
			test2[1][1] = *it;
		}

		regex pattern3("(^Depthcamera_right_xyz_z_delta:.*) (.*)$");
		smatch results3;
		if (regex_match(buf2, results3, pattern3)) {
			auto it = results3.begin();
			it != results3.end();
			++it;
			test2[2][0] = *it;

			++it;
			test2[2][1] = *it;
		}

		regex pattern4("(^Depthcamera_right_rpy_r_delta:.*) (.*)$");
		smatch results4;
		if (regex_match(buf2, results4, pattern4)) {
			auto it = results4.begin();
			it != results4.end();
			++it;
			test2[3][0] = *it;

			++it;
			test2[3][1] = *it;
			//cout << test2[3][1] << endl;
		}

		regex pattern5("(^Depthcamera_right_rpy_p_delta:.*) (.*)$");
		smatch results5;
		if (regex_match(buf2, results5, pattern5)) {
			auto it = results5.begin();
			it != results5.end();
			++it;
			test2[4][0] = *it;

			++it;
			test2[4][1] = *it;
		}
		regex pattern6("(^Depthcamera_right_rpy_y_delta:.*) (.*)$");
		smatch results6;
		if (regex_match(buf2, results6, pattern6)) {
			auto it = results6.begin();
			it != results6.end();
			++it;
			test2[5][0] = *it;

			++it;
			test2[5][1] = *it;
		}
	}
	//测试数组情况
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		cout << test2[i][j] << endl;
	//	}
	//}
	ifs1.close();

	string test3[37][2];
	ifstream ifs2;

	//3.打开文件3并且判断是否打开成功
	ifs2.open("test3.txt", ios::in);
	if (!ifs2.is_open())
	{
		cout << "文件2打开失败" << endl;
		return 0;
	}
	string buf3;
	while (getline(ifs2, buf3))
	{
		regex pattern1("(^DWAPlannerROS:.*) (.*)$");
		smatch results1;
		if (regex_match(buf3, results1, pattern1)) {
			auto it = results1.begin();
			it != results1.end();
			++it;
			test3[0][0] = *it;
			
			++it;
			test3[0][1] = *it;
		}

		regex pattern2("(^max_vel_x:.*) (.*)$");
		smatch results2;
		if (regex_match(buf3, results2, pattern2)) {
			auto it = results2.begin();
			it != results2.end();
			++it;
			test3[1][0] = *it;

			++it;
			test3[1][1] = *it;

			//cout << test3[1][0] << "/" << test3[1][1] << endl;
		}

		regex pattern3("(^max_trans_vel:.*) (.*)$");
		smatch results3;
		if (regex_match(buf3, results3, pattern3)) {
			auto it = results3.begin();
			it != results3.end();
			++it;
			test3[2][0] = *it;

			++it;
			test3[2][1] = *it;
		}
	
		regex pattern4("(^mobile_base_controller:.*) (.*)$");
		smatch results4;
		if (regex_match(buf3, results4, pattern4)) {
			auto it = results4.begin();
			it != results4.end();
			++it;
			test3[3][0] = *it;

			++it;
			test3[3][1] = *it;
		}

		regex pattern5("(^ twist_angzp_scale:.*) (.*)$");
		smatch results5;
		if (regex_match(buf3, results5, pattern5)) {
			auto it = results5.begin();
			it != results5.end();
			++it;
			test3[4][0] = *it;

			++it;
			test3[4][1] = *it;
		}

		regex pattern6("(^ twist_angzn_scale:.*) (.*)$");
		smatch results6;
		if (regex_match(buf3, results6, pattern6)) {
			auto it = results6.begin();
			it != results6.end();
			++it;
			test3[5][0] = *it;

			++it;
			test3[5][1] = *it;
		}

		regex pattern7("(^ twist_linxp_scale:.*) (.*)$");
		smatch results7;
		if (regex_match(buf3, results7, pattern7)) {
			auto it = results7.begin();
			it != results7.end();
			++it;
			test3[6][0] = *it;

			++it;
			test3[6][1] = *it;
		}

		regex pattern8("(^ twist_linxn_scale:.*) (.*)$");
		smatch results8;
		if (regex_match(buf3, results8, pattern8)) {
			auto it = results8.begin();
			it != results8.end();
			++it;
			test3[7][0] = *it;

			++it;
			test3[7][1] = *it;
		}

		regex pattern9("(^motor_control:.*) (.*)$");
		smatch results9;
		if (regex_match(buf3, results9, pattern9)) {
			auto it = results9.begin();
			it != results9.end();
			++it;
			test3[8][0] = *it;

			++it;
			test3[8][1] = *it;
		}

		regex pattern10("(^ motor_cmd_scale:.*) (.*)$");
		smatch results10;
		if (regex_match(buf3, results10, pattern10)) {
			auto it = results10.begin();
			it != results10.end();
			++it;
			test3[9][0] = *it;

			++it;
			test3[9][1] = *it;
		}

		regex pattern11("(^ motors_sign:.*) (.*)$");
		smatch results11;
		if (regex_match(buf3, results11, pattern11)) {
			auto it = results11.begin();
			it != results11.end();
			++it;
			test3[10][0] = *it;

			++it;
			test3[10][1] = *it;
		}

		regex pattern12("(^ invert_motors:.*) (.*)$");
		smatch results12;
		if (regex_match(buf3, results12, pattern12)) {
			auto it = results12.begin();
			it != results12.end();
			++it;
			test3[11][0] = *it;

			++it;
			test3[11][1] = *it;
		}

		regex pattern13("(^adjust_urdf:.*) (.*)$");
		smatch results13;
		if (regex_match(buf3, results13, pattern13)) {
			auto it = results13.begin();
			it != results13.end();
			++it;
			test3[12][0] = *it;

			++it;
			test3[12][1] = *it;
		}

		regex pattern14("(^ laser1_xyz_x_delta:.*) (.*)$");
		smatch results14;
		if (regex_match(buf3, results14, pattern14)) {
			auto it = results14.begin();
			it != results14.end();
			++it;
			test3[13][0] = *it;

			++it;
			test3[13][1] = *it;
		}

		regex pattern15("(^ laser1_xyz_y_delta:.*) (.*)$");
		smatch results15;
		if (regex_match(buf3, results15, pattern15)) {
			auto it = results15.begin();
			it != results15.end();
			++it;
			test3[14][0] = *it;

			++it;
			test3[14][1] = *it;
		}

		regex pattern16("(^ laser1_xyz_z_delta:.*) (.*)$");
		smatch results16;
		if (regex_match(buf3, results16, pattern16)) {
			auto it = results16.begin();
			it != results16.end();
			++it;
			test3[15][0] = *it;

			++it;
			test3[15][1] = *it;
		}

		regex pattern17("(^ laser1_rpy_r_delta:.*) (.*)$");
		smatch results17;
		if (regex_match(buf3, results17, pattern17)) {
			auto it = results17.begin();
			it != results17.end();
			++it;
			test3[16][0] = *it;

			++it;
			test3[16][1] = *it;
		}

		regex pattern18("(^ laser1_rpy_p_delta:.*) (.*)$");
		smatch results18;
		if (regex_match(buf3, results18, pattern18)) {
			auto it = results18.begin();
			it != results18.end();
			++it;
			test3[17][0] = *it;

			++it;
			test3[17][1] = *it;
		}

		regex pattern19("(^ laser1_rpy_y_delta:.*) (.*)$");
		smatch results19;
		if (regex_match(buf3, results19, pattern19)) {
			auto it = results19.begin();
			it != results19.end();
			++it;
			test3[18][0] = *it;

			++it;
			test3[18][1] = *it;
		}

		regex pattern20("(^ laser2_xyz_x_delta:.*) (.*)$");
		smatch results20;
		if (regex_match(buf3, results20, pattern20)) {
			auto it = results20.begin();
			it != results20.end();
			++it;
			test3[19][0] = *it;

			++it;
			test3[19][1] = *it;
		}

		regex pattern21("(^ laser2_xyz_y_delta:.*) (.*)$");
		smatch results21;
		if (regex_match(buf3, results21, pattern21)) {
			auto it = results21.begin();
			it != results21.end();
			++it;
			test3[20][0] = *it;

			++it;
			test3[20][1] = *it;
		}

		regex pattern22("(^ laser2_xyz_z_delta:.*) (.*)$");
		smatch results22;
		if (regex_match(buf3, results22, pattern22)) {
			auto it = results22.begin();
			it != results22.end();
			++it;
			test3[21][0] = *it;

			++it;
			test3[21][1] = *it;
		}

		regex pattern23("(^ laser2_rpy_r_delta:.*) (.*)$");
		smatch results23;
		if (regex_match(buf3, results23, pattern23)) {
			auto it = results23.begin();
			it != results23.end();
			++it;
			test3[22][0] = *it;

			++it;
			test3[22][1] = *it;
		}

		regex pattern24("(^ laser2_rpy_p_delta:.*) (.*)$");
		smatch results24;
		if (regex_match(buf3, results24, pattern24)) {
			auto it = results24.begin();
			it != results24.end();
			++it;
			test3[23][0] = *it;

			++it;
			test3[23][1] = *it;
		}

		regex pattern25("(^ laser2_rpy_y_delta:.*) (.*)$");
		smatch results25;
		if (regex_match(buf3, results25, pattern25)) {
			auto it = results25.begin();
			it != results25.end();
			++it;
			test3[24][0] = *it;
			++it;
			test3[24][1] = *it;
		}

		regex pattern26("(^Depthcamera_left_xyz_x_delta:.*) (.*)$");
		smatch results26;
		if (regex_match(buf3, results26, pattern26)) {
			auto it = results26.begin();
			it != results26.end();
			++it;
			test3[25][0] = *it;

			++it;
			test3[25][1] = *it;
		}

		regex pattern27("(^Depthcamera_left_xyz_y_delta:.*) (.*)$");
		smatch results27;
		if (regex_match(buf3, results27, pattern27)) {
			auto it = results27.begin();
			it != results27.end();
			++it;
			test3[26][0] = *it;

			++it;
			test3[26][1] = *it;
		}

		regex pattern28("(^Depthcamera_left_xyz_z_delta:.*) (.*)$");
		smatch results28;
		if (regex_match(buf3, results28, pattern28)) {
			auto it = results28.begin();
			it != results28.end();
			++it;
			test3[27][0] = *it;

			++it;
			test3[27][1] = *it;
		}

		regex pattern29("(^Depthcamera_left_rpy_r_delta:.*) (.*)$");
		smatch results29;
		if (regex_match(buf3, results29, pattern29)) {
			auto it = results29.begin();
			it != results29.end();
			++it;
			test3[28][0] = *it;

			++it;
			test3[28][1] = *it;
		}

		regex pattern30("(^Depthcamera_left_rpy_p_delta:.*) (.*)$");
		smatch results30;
		if (regex_match(buf3, results30, pattern30)) {
			auto it = results30.begin();
			it != results30.end();
			++it;
			test3[29][0] = *it;

			++it;
			test3[29][1] = *it;
		}

		regex pattern31("(^Depthcamera_left_rpy_y_delta:.*) (.*)$");
		smatch results31;
		if (regex_match(buf3, results31, pattern31)) {
			auto it = results31.begin();
			it != results31.end();
			++it;
			test3[30][0] = *it;

			++it;
			test3[30][1] = *it;
		}

		regex pattern32("(^Depthcamera_right_xyz_x_delta:.*) (.*)$");
		smatch results32;
		if (regex_match(buf3, results32, pattern32)) {
			auto it = results32.begin();
			it != results32.end();
			++it;
			test3[31][0] = *it;

			++it;
			test3[31][1] = *it;
		}

		regex pattern33("(^Depthcamera_right_xyz_y_delta:.*) (.*)$");
		smatch results33;
		if (regex_match(buf3, results33, pattern33)) {
			auto it = results33.begin();
			it != results33.end();
			++it;
			test3[32][0] = *it;

			++it;
			test3[32][1] = *it;
		}

		regex pattern34("(^Depthcamera_right_xyz_z_delta:.*) (.*)$");
		smatch results34;
		if (regex_match(buf3, results34, pattern34)) {
			auto it = results34.begin();
			it != results34.end();
			++it;
			test3[33][0] = *it;

			++it;
			test3[33][1] = *it;
		}

		regex pattern35("(^Depthcamera_right_rpy_r_delta:.*) (.*)$");
		smatch results35;
		if (regex_match(buf3, results35, pattern35)) {
			auto it = results35.begin();
			it != results35.end();
			++it;
			test3[34][0] = *it;

			++it;
			test3[34][1] = *it;
		}

		regex pattern36("(^Depthcamera_right_rpy_p_delta:.*) (.*)$");
		smatch results36;
		if (regex_match(buf3, results36, pattern36)) {
			auto it = results36.begin();
			it != results36.end();
			++it;
			test3[35][0] = *it;

			++it;
			test3[35][1] = *it;
		}

		regex pattern37("(^Depthcamera_right_rpy_y_delta:.*) (.*)$");
		smatch results37;
		if (regex_match(buf3, results37, pattern37)) {
			auto it = results37.begin();
			it != results37.end();
			++it;
			test3[36][0] = *it;

			++it;
			test3[36][1] = *it;
		}
	}


	//cout << test3[18][1] << endl;
	////测试数组情况
	//for (int i = 0; i < 37; i++)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		cout << test3[i][j] << endl;
	//	}
	//}
	ifs2.close();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 37; j++)
		{
			if (test2[i][0] == test3[j][0])
			{
				test3[j][1] = test2[i][1];
				//cout << j << endl;
			}
		}
	}
	////输出交换后数组test3
	//for (int i = 0; i < 37; i++)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		cout << test3[i][j] << endl;
	//	}
	//}

	ofstream ifs3;
	ifs3.open("test3.txt", ios::out);

	for (int i = 0; i < 37; i++)
	{
		ifs3 << test3[i][0] <<" "<< test3[i][1] << endl;
	}
	ifs3.close();

	system("pause");
	return 0;
}
