#include "lib/framework.hpp"
#define BULLET_MAX  29


bool Inside(float _pos1, float dis_max, float dis_min)
{
	if (_pos1 > dis_min && _pos1 < dis_max) return true;
	
	return false;
}

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 500
#define IS_FULL_SCREEN false
#define IS_DYNAMMIC_SCREEN true
class CApp 
{
public:
	static AppEnv& get()
	{ 
		static AppEnv s_env(WINDOW_WIDTH, WINDOW_HEIGHT, IS_FULL_SCREEN, IS_DYNAMMIC_SCREEN);
		return s_env;
	}
private: 
	CApp(){}
};

class Cnode  // ノード生成
{
public:
	Cnode()
	{
		icon.is_init = false;// 初期化用フラグ
		icon.is_active = true;

	};
	bool Init(float _x, float _y, Vec2f _size) // 初期化
	{
		if (icon.is_init)return false;
		icon.pos_x = _x;
		icon.pos_y = _y;
		icon.size = _size;
		icon.is_init = true;
		return true;
	};
	void Draw()// 描画処理
	{
		if (icon.is_active)
			drawFillCircle(icon.pos_x, icon.pos_y, icon.size.x(), icon.size.y(), 30, Color::red);
	}
	bool Is_active()
	{
		return icon.is_active;
	}

	void Is_dead()
	{
		icon.is_active = false;
	}

	void Move(float _speed)// 移動処理
	{
		if (icon.is_active)
		icon.pos_y -= _speed;
	}

	float Get_icon_pos_y()
	{
		return icon.pos_y;
	}

private:
	struct ICON //　ノートアイコン情報 
	{
		float pos_x;
		float pos_y;
		Vec2f size;
		bool is_active;
		bool is_init;
	};
	ICON icon;
};


class Cjudge 
{   // 判定用クラス
	
public:
	Cjudge()
	{
		score_plus = 0;
		combo = 0;
		judge_num = 0;
	};

	void draw()//判定してから書く
	{
		if (judge_num == JUDGE::EXCELENT)
			drawFillBox(-50,-50,100,100,Color::blue);
		if (judge_num == JUDGE::GOOD)
			drawFillBox(-50, -50, 100, 100, Color::red);
		if (judge_num == JUDGE::BAD)
			drawFillBox(-50, -50, 100, 100, Color::yellow);


	}

	void Is_draw_active(float _icon_pos_y)//Insideがtrueのときさらに判定
	{

		if (Inside(_icon_pos_y, -185, -215))
		{   
		   judge_num =JUDGE::EXCELENT;
		}
		else if (Inside(_icon_pos_y, -165, -185) || Inside(_icon_pos_y, -215, -235))
		{
			judge_num = JUDGE::GOOD;
		}
		else judge_num= JUDGE::BAD;

	}
	int Score(int _score)
	{
		score_plus = combo * 10;

		return _score + score_plus;
	}
	int Combo(int _combo)
	{
		combo = _combo + 1;
		return combo;
	}
private:
	enum JUDGE  // ジャスト判定
	{
		BAD,
		GOOD,
		EXCELENT
	};
	int score_plus;
	int combo;
	int draw_time;
	int judge_num;;
	bool is_draw_active;
};
float lastFrameTime = clock();
float deltaTime = 0.0f;

int main() 
{
	CApp::get();


	Media sio("res/SIO.wav");
	int pos_x[5] = { -200, -100, 0, 100, 200 };
	bool is_hit[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		is_hit[i] = true;
	}
	float icon_x[] = 
	{
		-200,200,-100,100,-200,  -100, 100,200,100,-100,
		100,200,-100,-200,200,    200,100,-100,-200,-200,
		-200,-100,100,200,200,    200,100,-100,-200
	};
	float icon_y[] =
	{
		950/4, 2200/4, 2400/4, 2600/4, 3500/4, 4400/4, 4600/4, 4800/4, 5000/4, 5200/4,
		5400/4, 5600/4, 5800/4, 6050/4, 7000/4, 7100/4, 7300/4, 7450/4, 7600/4, 8700/4,
		8800/4, 9000/4, 9150/4, 9300/4, 10400/4, 10500/4, 10700/4, 10850/4, 11000/4,
	};
	Vec2f icon_size = Vec2f(15.5f,6.25f);
	Cnode Note[BULLET_MAX]; // ノートを29個分生成
	Cjudge judge = Cjudge();
	float geter_icon_pos_y[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		geter_icon_pos_y[i] = 0;
	}
	sio.play();
	bool temp_flag[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		temp_flag[i] = false;
	}
	while (CApp::get().isOpen()) 
	{
		CApp::get().begin();
		deltaTime = clock() - lastFrameTime;  // 移動用デルタタイム
		lastFrameTime = clock();

		for (int i = 0; i < 5; ++i)
		{
			drawFillCircle(pos_x[i], -200, 30, 7.5, 30, Color::red);
		}

		for (int i = 0; i < BULLET_MAX; ++i)
		{
			Note[i].Init(icon_x[i], icon_y[i], icon_size); // 一回のみ初期化
			Note[i].Draw(); // 描画処理
			Note[i].Move(deltaTime * 0.15f);  // 移動処理　
		}

		for (int i = 0; i < BULLET_MAX; ++i)
		{
			geter_icon_pos_y[i] = Note[i].Get_icon_pos_y();
		}


		if (CApp::get().isPushKey('A'))
		{
			for (int i = 0; i < BULLET_MAX; ++i)
			{
				if (!temp_flag[i] && Inside(geter_icon_pos_y[i], -150, -250))
				{
					
					temp_flag[i] = true;
					break;
				}
			}
		}
		for (int i = 0; i < BULLET_MAX; ++i)
		{
			//if (!Note[i].Is_active()) continue;

			if (temp_flag[i] == true)
			{
				Note[i].Is_dead();
				judge.Is_draw_active(geter_icon_pos_y[i]);
				judge.draw();
			}
		}
    CApp::get().end();
  }
}
