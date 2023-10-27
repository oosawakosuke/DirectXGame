#pragma once

#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include "DebugText.h"
#include "Audio.h"
#include "WinApp.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // 静的メンバ変数
	static const int debugTextTexNumber = 0;

public: // メンバ関数

	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	void DrawMiniMap();

	void PlayerMove(); //プレイヤー移動
	void BigenemyMove();//大型艦移動
	void MiniUnitMove();//味方小型艦移動
	void MidiumEnemyBorn();//中型艦生成
	void MidiumEnemyMove();//中型艦移動
	void MiniEnemyBorn();//小型艦生成
	void MiniEnemyMove();//小型艦移動
	void TamaMove();//弾移動
	void TamaBorn();//弾生成
	void EiseiBeamBorn();//衛星ビームの生成
	void EiseiBeamMove();//衛星ビームの移動
	void AhatoTamaMove();//小型弾移動
	void AhatoTamaBorn();//小型弾生成
	void CollisionTama();//敵と弾の当たり判定
	void PlanetPosition();//惑星位置
	void CollosionPlanet();//惑星と弾の当たり判定
	void PlanetBorn();//惑星と弾生成

	void EiseiBorn();//衛星の生成

	void MissileBorn();//ミサイル生成
	void MissileMove();//ミサイル移動
	void PlayerCollision();//自機と弾の当たり判定
	void ExplosionBorn();//爆発の場所
	void MiniExplosionBorn();//mini爆発の場所
	void FivewayMove();//5wayの移動
	void FivewayBorn();//5wayの生成
	void Resporn(); //リスポーン
	void FivewayCollision();//プレイヤーと５連射の当たり判定
	void MidiumCollisionTama();//中型艦とプレイヤー弾の当たり判定
	void MiniUnitCollisionTama();//小型艦とプレイヤー弾の当たり判定
	void EiseibeamCollision();//衛星ビームの当たり判定
	void MidiumTamaBorn();//中型艦と弾の当たり判定
	void MiniUnitTamaBorn();//小型艦と弾の当たり判定
	void ThreewayBorn();//スリーウェイ
	void ThreewayMove();//3way
	void ThreewayCollision();//3way当たり判定
	void HpbarBorn();//HPバーの生成(大)
	void HpbarBornM();//HPバーの生成（中）
	void HpbarBornBigUnit();//要塞のHPバー
	void HpbarBornPlayer();//プレイヤーのHPバー
	void HpbarBornPlanet();//惑星のHPバー
	void MiniUnitCollisionEitway();//要塞の弾と小型艦の当たり判定

	void BigUnitMove();//味方基地移動
	void BigUnitEitwayBorn();//基地攻撃手段
	void BigUnitEitwayMove();//基地攻撃手段
	void EitwayCollision();//3way当たり判定
	void AhatoCollision();//単発弾の当たり判定
	private: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	DebugText debugText;
	/// <summary>
	
	/// ゲームシーン用
	void GamePlayUpdate();
	void GamePlayDraw3D();
	int sceneMode = 1;//シーンモード0ゲームプレイ 1クリア 2ゲームオーバー
	void TitleUpdate();
	void TitleDraw2D();
	void OverUpdate();
	void OverDraw2D();
	void ClearUpdate();
	void ClearDraw2D();
	void GamePlayStart();
	//タイトル系
	Sprite* spriteTitle = nullptr;  //タイトル
	Sprite* spriteOver = nullptr; //ゲームオーバー
	Sprite* spriteClear = nullptr; //ゲームオーバー
	/// </summary>
	Sprite* spriteBG[20][20] = {};
	Object3d* object3d = nullptr;
	Sprite* spritePlayer = nullptr;
	Sprite* spritePlayerTenmetu = nullptr;
	Sprite* spriteBigenemy[20] = {};

	//マップ座標
	float mapX = 0;
	float mapY = 0;

	//プレイヤー
	float playerX = WinApp::window_width /2;
	float playerY = WinApp::window_height/2;
	int playerFlag = 0;
	int playerHp = 0;
	int playerTimer = 0;
	Sprite* spritePlayerHpbar = 0;

	//小型艦
	Sprite* spriteKogataEnemy[60] = {};
	Sprite* spriteKogataEnemy2[60] = {};
	float MiniUnitX[60] = {};
	float MiniUnitY[60] = {};
	float MiniUnitFlag[60] = {};
	float MiniUnitHp[60] = {};

	//味方基地
	Sprite* spriteBigUnit = nullptr;
	float bigunitX = 0; //味方要塞
	float bigunitY = 0; //味方要塞
	int bigunitFlag = 0;
	int bigunitHp = 0;
	float EitRangeX = 2000;//8ウェイ
	float EitRangeY = 2000;//8ウェイ
	float bDir = 0;
	float bDir2 = 0;
	float bigunitRespornTimer = 0;//大型艦のリスポーン
	Sprite* spriteHpbarYousai = 0;//要塞HPバー

	//味方小型艦
	Sprite* spriteKogataUnit[10] = {};
	float kogataMikataX[10] = {};
	float kogataMikataY[10] = {};
	int kogataMikataFlag[10] = {};
	int kogataMikataHp[10] = {};
	float kogataMikataDir[10] = {};

	//敵中型艦
	Sprite* spriteMidiumEnemy[40] = {};
	float MidiumX[40] = {};
	float MidiumY[40] = {};
	int midiumEnemyFlag[40] = {};
	int midiumHp[40] = {};
	float MidiumRespornTimer[40] = {};
	float TrayTimer[40] = {};
	Sprite* spriteHpbarMidium[40] = {};

	//敵大型艦座標
	float BigX[20] = {};
	float BigY[20] = {};
	int enemyFlag[20] = {};
	int BigHp[20] = {};
	float Range = 1000;//大型艦の停止距離
	float MisoRangeX = 850;
	float MisoRangeY = 850;
	int BigMisoTimer[20] = {};
	float FivewayRangeX = 800;
	float FivewayRangeY = 800;
	int BigWayTimer[20] = {};
	int RespornTimer[20] = {};
	
	//戦闘衛星
	Sprite* spriteEisei[20] = {};
	//int EiseiFlag[20] = {};
	float EiseiX[20] = {};
	float EiseiY[20] = {};
	float EiseiDir[20] = {};

	//戦闘衛星ビーム弾
	Sprite* spriteEiseibeam[200] = {};
	int EiseibeamFlag[200] = {};
	float EiseibeamX[200] = {};
	float EiseibeamY[200] = {};
	int EiseibeamCount[10] = {};
	float EiseibeamDir[200] = {};
	float EiseibeamDir3[200] = {};


	//実体弾座標
	Sprite* spriteTama[100] = {};
	float TamaX[100] = {};
	float TamaY[100] = {};
	float Dir[100] = {};
	float Dir3[100] = {};
	int TamaFlag[100] = {};
	int shotTimer = 0;
	int tCount[100] = {};

	//単発弾
	Sprite* spriteAHATO[100] = {};
	float AhatoTamaX[100] = {};
	float AhatoTamaY[100] = {};
	float AhatoDir[100] = {};
	float AhatoDir3[100] = {};
	int AhatoTamaFlag[100] = {};
	int AhatoshotTimer[100] = {};
	int AhatoCount[100] = {};
	int AhatoWayTimer[100] = {};
	int AhatoRayTimer[100] = {};
	int AhatoWayFlag[100] = {};
	int ahatoRayTimer[100] = {};

	//防御艦
	Sprite* spriteDeF[10] = {};
	float DefX[10] = {};
	float DefY[10] = {};

	//惑星
	Sprite* spritePlanet[20] = {};
	Sprite* spritePlanetHpbar[20] = {};
	float PlanetX[20] = {};
	float PlanetY[20] = {};
	int PlanetFlag[20] = {};
	int PlanetHp[20] = {};

	//ミサイル
	Sprite* spriteMissile[100] = {};
	float MissileX[100] = {};
	float MissileY[100] = {};
	int MissileFlag[100] = {};
	float mDir[100] = {};
	float mDir3[100] = {};
	int formingFlag[100] = {};
	int misoTimer[100] = {};

	//爆発エフェクト
	Sprite* spriteExplosion[100] = {};
	int explosionFlag[100] = {};
	float exX[100] = {};
	float exY[100] = {};
	int explosionTimer[100] = {};

	//爆発エフェクト
	Sprite* spriteMiniExplosion[100] = {};
	int miniexplosionFlag[100] = {};
	float miniexX[100] = {};
	float miniexY[100] = {};
	int miniexplosionTimer[100] = {};

	//5wayショット
	Sprite* spriteFiveway[300] = {};
	int fivewayFlag[300] = {};
	float fivewayX[300] = {};
	float fivewayY[300] = {};
	int fivewayTimer[300] = {};
	float fDir[300] = {};
	float fDir3[300] = {};
	int waytimer[300] = {};

	//8wayショット
	Sprite* spriteEitway[300] = {};
	int eitwayFlag[300] = {};
	float EitwayX[300] = {};
	float EitwayY[300] = {};
	int EitWayTimer[300] = {};
	float eDir[300] = {};
	float eDir3[300] = {};
	int eitwayTimer[300] = {};
	int ErayTimer[300] = {};
	int test = 0;

	//3wayショット
	Sprite* spriteThreeway[300] = {};
	int threewayFlag[300] = {};
	float threewayX[300] = {};
	float threewayY[300] = {};
	int threewayTimer[300] = {};
	float tDir[300] = {};
	float tDir3[300] = {};
	int threewaytimer[300] = {};

	//HP関連リソース
	Sprite* spriteHpbarGreen[20] = {};

	//ミニマップ系列
	Sprite* spriteMiniEnemy[20] = {};
	Sprite* spriteMiniPlanet[20] = {};
	Sprite* spriteMiniPlayer = 0;
	Sprite* spriteMiniNormalEnemy[40] = {};
	Sprite* spriteMiniMiss[100] = {};
	Sprite* spriteYousai = 0;
	Sprite* spriteBackMini = 0;
	Sprite* spriteMiniUnit[60] = {};
};

