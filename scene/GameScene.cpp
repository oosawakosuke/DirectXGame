#include "GameScene.h"
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <WinApp.h>

using namespace DirectX;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			safe_delete(spriteBG[y][x]);
		}
	}
	
	safe_delete(object3d);
	safe_delete(spritePlayer);
	safe_delete(spritePlayerTenmetu);

	for (int i = 0; i < 20; i++)
	{
		safe_delete(spriteBigenemy[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		safe_delete(spriteTama[i]);
	}
	for (int i = 0; i < 20; i++)
	{
		safe_delete(spritePlanet[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		safe_delete(spriteMissile[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		safe_delete(spriteExplosion[i]);
	}
	for (int i = 0; i < 300; i++)
	{
		safe_delete(spriteFiveway[i]);
	}
	for (int i = 0; i < 300; i++)
	{
		safe_delete(spriteThreeway[i]);
	}
	for (int i = 0; i < 200; i++)
	{
		safe_delete(spriteEiseibeam[i]);
	}
	for (int i = 0; i < 20; i++)
	{
		safe_delete(spriteMiniEnemy[i]);
	}
	for (int i = 0; i < 20; i++)
	{
		safe_delete(spriteMiniPlanet[i]);
	}
	safe_delete(spriteMiniPlayer);
	for (int i = 0; i < 100; i++)
	{
		safe_delete(spriteMiniExplosion[i]);
	}
	safe_delete(spriteTitle);//タイトル
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{

	//乱数
	srand(time(NULL));

	// nullptrチェック
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	// テクスチャ読み込み
	if (!Sprite::LoadTexture(1, L"Resources/background.png")) {
		assert(0);
		return;
	}

	//テクスチャ読み込み player
	if (!Sprite::LoadTexture(2, L"Resources/texture.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み 大型艦
	if (!Sprite::LoadTexture(3, L"Resources/BigEnemy.png"))
	{
		assert(0);
		return;
	}

	//中型艦
	if (!Sprite::LoadTexture(13, L"Resources/MidiumEnemy.png"))
	{
		assert(0);
		return;
	}
	
	//小型艦
	if (!Sprite::LoadTexture(38, L"Resources/kogata.png"))
	{
		assert(0);
		return;
	}

	//小型艦点滅
	if (!Sprite::LoadTexture(39, L"Resources/kogata2.png"))
	{
		assert(0);
		return;
	}

	//要塞(20個)
	if (!Sprite::LoadTexture(32, L"Resources/eisei.png"))
	{
		assert(0);
		return;
	}

	//３way弾
	if (!Sprite::LoadTexture(14, L"Resources/ThreewayBullet.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み 実体弾
	if (!Sprite::LoadTexture(4, L"Resources/bullet.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み 惑星
	if (!Sprite::LoadTexture(5, L"Resources/Space.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み 惑星
	if (!Sprite::LoadTexture(6, L"Resources/missile.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　爆発
	if (!Sprite::LoadTexture(7, L"Resources/explosion.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　mini爆発
	if (!Sprite::LoadTexture(15, L"Resources/MiniEx.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　味方基地
	if (!Sprite::LoadTexture(16, L"Resources/Kyoten.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　味方小型艦
	if (!Sprite::LoadTexture(70, L"Resources/corefighter.png"))
	{
		assert(0);
		return;
	}


	//テクスチャ読み込み　5way弾
	if (!Sprite::LoadTexture(8, L"Resources/EnemyBullet.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　単発弾
	if (!Sprite::LoadTexture(88, L"Resources/AHATO.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ビーム
	if (!Sprite::LoadTexture(35, L"Resources/green.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　８way
	if (!Sprite::LoadTexture(80, L"Resources/EitBllet.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　防御ユニット？？
	if (!Sprite::LoadTexture(9, L"Resources/Defunit.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　プレイヤー点滅
	if (!Sprite::LoadTexture(232, L"Resources/texture2.png"))
	{
		assert(0);
		return;
	}


	//テクスチャ読み込み　ミニマップ素材背景
	if (!Sprite::LoadTexture(100, L"Resources/backMini.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材敵
	if (!Sprite::LoadTexture(10, L"Resources/miniEnemy.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材星
	if (!Sprite::LoadTexture(11, L"Resources/miniPlanet.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材プレイヤー
	if (!Sprite::LoadTexture(12, L"Resources/miniPlayer.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材小型艦
	if (!Sprite::LoadTexture(17, L"Resources/KogataMiniMap.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材中型艦
	if (!Sprite::LoadTexture(20, L"Resources/miniNormalEnemy.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材ミサイル
	if (!Sprite::LoadTexture(23, L"Resources/miniMis.png"))
	{
		assert(0);
		return;
	}

	//テクスチャ読み込み　ミニマップ素材ミサイル
	if (!Sprite::LoadTexture(30, L"Resources/miniunit.png"))
	{
		assert(0);
		return;
	}

	//HPバー緑
	if (!Sprite::LoadTexture(101, L"Resources/HPbarG.png"))
	{
		assert(0);
		return;
	}

	//HPバー青
	if (!Sprite::LoadTexture(102, L"Resources/HPbarB.png"))
	{
		assert(0);
		return;
	}

	//タイトル画像
	if (!Sprite::LoadTexture(200, L"Resources/Title.png"))
	{
		assert(0);
		return;
	}

	//ゲームオーバー画像
	if (!Sprite::LoadTexture(201, L"Resources/Over.png"))
	{
		assert(0);
		return;
	}

	//ゲームクリア画像
	if (!Sprite::LoadTexture(202, L"Resources/Clear.png"))
	{
		assert(0);
		return;
	}


	// 背景スプライト生成
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			spriteBG[y][x] = Sprite::Create(1, { x * 1280.0f,y * 720.0f });
		}
	}
	//プレイヤーの生成
	spritePlayer = Sprite::Create(2, { 0.0f,0.0f });
	spritePlayerTenmetu = Sprite::Create(232, { 0.0f,0.0f });
	playerFlag = 1;
	playerHp = 10000;

	//味方小型艦の生成
	for (int i = 0; i < 10; i++)
	{
		spriteKogataUnit[i] = Sprite::Create(70, { 0.0f,0.0f });
		kogataMikataFlag[i] = 1;
	}

	//味方基地の生成
	spriteBigUnit = Sprite::Create(16, { 0.0f,0.0f });
	bigunitFlag = 1;
	bigunitHp = 1500;
	bigunitRespornTimer = 1000;

	//敵中型艦生成
	for (int i = 0; i < 40; i++)
	{
		spriteMidiumEnemy[i] = Sprite::Create(13, { 0.0f, 0.0f });
	}

	//敵小型艦生成
	for (int i = 0; i < 60; i++)
	{
		spriteKogataEnemy[i] = Sprite::Create(38, { 0.0f, 0.0f });
	}

	//敵小型艦生成
	for (int i = 0; i < 60; i++)
	{
		spriteKogataEnemy2[i] = Sprite::Create(39, { 0.0f, 0.0f });
	}

	//敵大型艦生成
	for (int i = 0; i < 20; i++)
	{
		spriteBigenemy[i] = Sprite::Create(3, { 0.0f, 0.0f });
	}

	//敵戦闘衛星
	for (int i = 0; i < 20; i++)
	{
		spriteEisei[i] = Sprite::Create(32, { 0.0f, 0.0f });
	}

	//実体弾
	for (int i = 0; i < 100; i++)
	{
		spriteTama[i] = Sprite::Create(4, { 0.0f,0.0f });
	}

	//単発弾
	for (int i = 0; i < 100; i++)
	{
		spriteAHATO[i] = Sprite::Create(88, { 0.0f,0.0f });
		spriteAHATO[i]->SetSize({ 100,100 });
	}

	//惑星生成
	for (int i = 0; i < 20; i++)
	{
		spritePlanet[i] = Sprite::Create(5, { 0.0f,0.0f });
	}

	//爆発生成
	for (int i = 0; i < 100; i++)
	{
		spriteExplosion[i] = Sprite::Create(7, { 0.0f,0.0f });
	}

	//mini爆発生成
	for (int i = 0; i < 100; i++)
	{
		spriteMiniExplosion[i] = Sprite::Create(15, { 0.0f,0.0f });
	}


	//missile生成
	for (int i = 0; i < 100; i++)
	{
		spriteMissile[i] = Sprite::Create(6, { 0.0f,0.0f });
	}

	//8way生成
	for (int i = 0; i < 300; i++)
	{
		spriteEitway[i] = Sprite::Create(80, {0.0f,0.0f});
	}

	//5way生成
	for (int i = 0; i < 300; i++)
	{
		spriteFiveway[i] = Sprite::Create(8, { 0.0f,0.0f });
	}

	//3way生成
	for (int i = 0; i < 300; i++)
	{
		spriteThreeway[i] = Sprite::Create(14, { 0.0f,0.0f });
	}

	//戦闘衛星ビーム
	for (int i = 0; i < 200; i++)
	{
		spriteEiseibeam[i] = Sprite::Create(35, { 0.0f,0.0f });
		EiseibeamFlag[i] = 0;
		spriteEiseibeam[i]->SetAnchorPoint({ 0.5f,0.5f });
		spriteEiseibeam[i]->SetSize({ 0.0f,0.0f });
	}

	//ミニ惑星
	for (int i = 0; i < 20; i++)
	{
		spriteMiniPlanet[i] = Sprite::Create(11, { 0.0f,0.0f });
	}

	//ミニ小型艦
	for (int i = 0; i < 60; i++)
	{
		spriteMiniUnit[i] = Sprite::Create(17, { 0.0f,0.0f });
	}

	//ミニ敵
	for (int i = 0; i < 20; i++)
	{
		spriteMiniEnemy[i] = Sprite::Create(10, { 0.0f,10.0f });
	}

	//ミニ敵
	for (int i = 0; i < 40; i++)
	{
		spriteMiniNormalEnemy[i] = Sprite::Create(20, { 0.0f,10.0f });
	}

	//ミニミサイル
	for (int i = 0; i < 100; i++)
	{
		spriteMiniMiss[i] = Sprite::Create(23, { 0.0f,10.0f });
	}

	//大型艦HPバー
	for (int i = 0; i < 20; i++)
	{
		spriteHpbarGreen[i] = Sprite::Create(101, { 0.0f,0.0f });
	}

	//中型艦HPバー
	for (int i = 0; i < 40; i++)
	{
		spriteHpbarMidium[i] = Sprite::Create(101, { 0.0f,0.0f });
	}

	//惑星のHPバー
	for (int i = 0; i < 20; i++)
	{
		spritePlanetHpbar[i] = Sprite::Create(102, { 0.0f,0.0f });
	}

	//要塞のHpバー
	spriteYousai = Sprite::Create(101, { 0.0f,0.0f });

	//プレイヤーのHpバー
	spritePlayerHpbar = Sprite::Create(101, { 0.0f,0.0f });

	//ミニユニット
	spriteYousai = Sprite::Create(30, { 0.0f,10.0f });


	//ミニプレイヤー
	spriteMiniPlayer = Sprite::Create(12, { 0.0f,20.0f });

	//ミニプレイヤー
	spriteBackMini = Sprite::Create(100, { 0.0f,0.0f });

	/////シーン
	//タイトル
	spriteTitle = Sprite::Create(200, { 0.0f,0.0f });

	//ゲームオーバー
	spriteOver = Sprite::Create(201, { 0.0f,0.0f });

	//ゲームクリア
	spriteClear = Sprite::Create(202, { 0.0f,0.0f });
	
	//プレイヤーの初期座標
	spritePlayer->SetPosition({ 0,0 });

	// 3Dオブジェクト生成
	object3d = Object3d::Create();
	object3d->Update();

	//惑星生成
	for (int i = 0; i < 10; i++)
	{
		PlanetFlag[i] = 1;
		PlanetHp[i] = 600;

		PlanetX[i] = rand() % 3000 + 25600;
		PlanetY[i] = rand() % 3000 + 14400;
	}

	//敵のランダム生成
	for (int i = 0; i < 10; i++)
	{
		enemyFlag[i] = 0;
		BigHp[i] = 60;

		BigX[i] = PlanetX[i];
		BigY[i] = PlanetY[i];

		RespornTimer[i] = 1000;
	}
	for (int i = 0; i < 10; i++)
	{

		enemyFlag[i + 10] = 0;
		BigHp[i + 10] = 60;

		BigX[i + 10] = PlanetX[i];
		BigY[i + 10] = PlanetY[i];

		RespornTimer[i] = 1000;
	}
	//敵中型艦の生成
	for (int i = 0; i < 10; i++)
	{
		for (int m = 0; m < 20; m++)
		{
			midiumEnemyFlag[i] = 0;
			midiumHp[i] = 20;

			MidiumX[i] = PlanetX[m];
			MidiumY[i] = PlanetY[m];

			MidiumRespornTimer[i] = 500;
		}
	}

	//敵小型艦の生成
	for (int i = 0; i < 60; i++)
	{
		for (int m = 0; m < 20; m++)
		{
			MiniUnitFlag[i] = 0;
			MiniUnitHp[i] = 10;

			MiniUnitX[i] = PlanetX[m];
			MiniUnitY[i] = PlanetY[m];
		}
	}

	//戦闘衛星ビームの生成
	for (int i = 0; i < 200; i++)
	{

	}

	//戦闘衛星の生成
	//for (int i = 0; i < 10; i++)
	//{
	//	EiseiFlag[i] = 1;
	//}
}


void GameScene::Update()
{
	switch (sceneMode)
	{
	case 0:
		GamePlayUpdate();
		break;
	case 1:
		TitleUpdate();
		break;
	case 2:
		OverUpdate();
		break;
	case 3:
		ClearUpdate();
		break;
		
	}
	//Sleep(50);
	//// オブジェクト移動
	//if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
	//{
	//	// 現在の座標を取得
	//	XMFLOAT3 position = object3d->GetPosition();

	//	// 移動後の座標を計算
	//	//if (input->PushKey(DIK_UP)) { position.y += 1.0f; }
	//	//else if (input->PushKey(DIK_DOWN)) { position.y -= 1.0f; }
	//	//if (input->PushKey(DIK_RIGHT)) { position.x += 1.0f; }
	//	//else if (input->PushKey(DIK_LEFT)) { position.x -= 1.0f; }

	//	// 座標の変更を反映
	//	object3d->SetPosition(position);
	//}
	
	// //カメラ移動
	//if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
	//{
	//	if (input->PushKey(DIK_W)) { Object3d::CameraMoveVector({ 0.0f,4.0f,0.0f }); }
	//	else if (input->PushKey(DIK_S)) { Object3d::CameraMoveVector({ 0.0f,-4.0f,0.0f }); }
	//	if (input->PushKey(DIK_D)) { Object3d::CameraMoveVector({ +4.0f,0.0f,0.0f }); }
	//	else if (input->PushKey(DIK_A)) { Object3d::CameraMoveVector({ -4.0f,0.0f,0.0f }); }
	//}

}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(cmdList);
	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	switch (sceneMode)
	{
	case 0:
		GamePlayDraw3D();
		break;
	case 1:
		TitleDraw2D();
		break;
	case 2:
		OverDraw2D();
		break;
	case 3:
		ClearDraw2D();
		break;
	}

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(cmdList);

	// 3Dオブクジェクトの描画
	//object3d->Draw();

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	//数値の表示
	char str[100];
	char str2[100];
	char str3[100];
	char str4[100];
	char str5[100];
	//sprintf_s(str, "X=%d", (int)mapX);
	//sprintf_s(str2, "Y=%d", (int)AhatoTamaFlag);
	//sprintf_s(str3, "HP=%d", (int)playerHp);
	//sprintf_s(str4, "eisei=%d", (int)EiseibeamFlag);
	//sprintf_s(str2, "unitHP=%d", (int)bigunitHp);
	//for (int i = 0 ; i < 10; i++)
	//{
	//	sprintf_s(str5, "planetflag=%d", (int)PlanetFlag[i]);
	//	debugText.Print(str5, 10, 300 + i * 20, 2);
	//}
	debugText.Print(str, 10, 100, 2);
	debugText.Print(str2, 10, 150, 2);
	debugText.Print(str3, 10, 200, 2);
	debugText.Print(str4, 10, 250, 2);
	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(cmdList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText.DrawAll(cmdList);

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}

void GameScene::PlayerMove()
{
	if (playerFlag == 1)
	{
		int x = 15;
		spritePlayer->SetAnchorPoint({ 0.5f,0.5f });
		spritePlayerTenmetu->SetAnchorPoint({ 0.5f,0.5f });

		int a = 0;

		if (input->PushKey(DIK_RIGHT))
		{
			mapX += x;
			playerX += x;
			spritePlayer->SetRotation(0);
			spritePlayerTenmetu->SetRotation(0);
			playerTimer++;
		}
		if (input->PushKey(DIK_LEFT))
		{
			mapX -= x;
			playerX -= x;
			spritePlayer->SetRotation(180);
			spritePlayerTenmetu->SetRotation(180);
			playerTimer++;
		}
		if (input->PushKey(DIK_DOWN))
		{
			mapY += x;
			playerY += x;
			spritePlayer->SetRotation(90);
			spritePlayerTenmetu->SetRotation(90);
			playerTimer++;
		}
		if (input->PushKey(DIK_UP))
		{
			mapY -= x;
			playerY -= x;
			spritePlayer->SetRotation(-90);
			spritePlayerTenmetu->SetRotation(-90);
			playerTimer++;
		}

		if (input->PushKey(DIK_UP)&&input->PushKey(DIK_LEFT))
		{
			spritePlayer->SetRotation(225);
			spritePlayerTenmetu->SetRotation(225);
		}

		if (input->PushKey(DIK_UP) && input->PushKey(DIK_RIGHT))
		{
			spritePlayer->SetRotation(-45);
			spritePlayerTenmetu->SetRotation(-45);
		}
		if (input->PushKey(DIK_DOWN) && input->PushKey(DIK_LEFT))
		{
			spritePlayer->SetRotation(90+45);
			spritePlayerTenmetu->SetRotation(90+45);
		}
		if (input->PushKey(DIK_DOWN) && input->PushKey(DIK_RIGHT))
		{
			spritePlayer->SetRotation(45);
			spritePlayerTenmetu->SetRotation(45);
		}

		//プレイヤー座標
		spritePlayer->SetPosition({ playerX - mapX, playerY - mapY });
		spritePlayerTenmetu->SetPosition({ playerX - mapX, playerY - mapY });
	}
}

void GameScene::BigenemyMove()
{
	//敵座標
	for (int i = 0; i < 20; i++)
	{
		if (enemyFlag[i] == 1)
		{

			spriteBigenemy[i]->SetPosition({ BigX[i] - mapX ,BigY[i] - mapY });

			//プレイヤー方向へ向く計算
			float Dir = atan2(playerY - BigY[i], playerX - BigX[i]);
			float Dir2 = Dir * (180.0f / 3.14);

			//中心の指定
			spriteBigenemy[i]->SetAnchorPoint({ 0.5,0.5 });
			//回転
			spriteBigenemy[i]->SetRotation(Dir2);

			int Range2 = Range;

			if (i < 10)
			{
				Range2 = 0;
			}

			if (playerX - Range2 > BigX[i])
			{
				BigX[i] += 2;
			}

			if (playerX + Range2 < BigX[i])
			{
				BigX[i] -= 2;
			}

			if (playerY - Range2 > BigY[i])
			{
				BigY[i] += 2;
			}
			if (playerY + Range2 < BigY[i])
			{
				BigY[i] -= 2;
			}

		}
	}
}

void GameScene::MiniUnitMove()//味方小型艦移動
{
	for (int i = 0; i < 10; i++)
	{
		if (kogataMikataFlag[i] == 1)
		{
			kogataMikataX[i] = playerX + cos(kogataMikataDir[i]) * 250;
			kogataMikataY[i] = playerY + sin(kogataMikataDir[i]) * 250;

			spriteKogataUnit[i]->SetPosition({ kogataMikataX[i] - mapX,kogataMikataY[i] - mapY });
			spriteKogataUnit[i]->SetSize({ 100.0f,100.0f });
			spriteKogataUnit[i]->SetAnchorPoint({ 0.5f,0.5f });
			kogataMikataDir[i] += 0.01;

		}
	}
}

void GameScene::TamaMove()
{
	if (playerFlag == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (TamaFlag[i] == 1)
			{

				TamaX[i] += cos(Dir[i]) * 20;
				TamaY[i] += sin(Dir[i]) * 20;

				//弾座標
				spriteTama[i]->SetPosition({ TamaX[i] - mapX, TamaY[i] - mapY });

				tCount[i] += 1;
				if (tCount[i] > 300)
				{
					TamaFlag[i] = 0;
				}
			}
		}
	}
}

void GameScene::AhatoTamaMove()
{
	for (int i = 0; i < 100; i++)
	{
		if (AhatoTamaFlag[i] == 1)
		{
			//中心点
			spriteAHATO[i]->SetAnchorPoint({ 0.5f,0.5f });
			//回転
			spriteAHATO[i]->SetRotation(AhatoDir3[i]);

			//当たり判定が不明

			AhatoTamaX[i] += cos(AhatoDir[i]) * 7;//単発弾速度
			AhatoTamaY[i] += sin(AhatoDir[i]) * 7;//単発弾速度
			//弾座標
			spriteAHATO[i]->SetPosition({ AhatoTamaX[i] - mapX, AhatoTamaY[i] - mapY });

			AhatoCount[i] += 1;
			if (AhatoCount[i] > 300)
			{
				AhatoTamaFlag[i] = 0;
			}
		}
	}
}

void GameScene::TamaBorn()
{
	if (shotTimer == 0)
	{
		for (int t = 0; t < 20; t++)
		{
			if (enemyFlag[t] == 1)
			{
				//プレイヤーと敵の座標が近ければ撃つ
				float dx = abs(BigX[t] - playerX);
				float dy = abs(BigY[t] - playerY);

				if (dx < 800 && dy < 800)//実体弾射程距離
				{
					for (int i = 0; i < 100; i++)
					{
						if (TamaFlag[i] == 0)
						{
							TamaX[i] = playerX;
							TamaY[i] = playerY;

							//敵方向に向く計算
							Dir[i] = atan2(BigY[t] - TamaY[i], BigX[t] - TamaX[i]);
							Dir3[i] = Dir[i] * (180.0f / 3.14);

							//回転
							spriteTama[i]->SetRotation(Dir3[i]);

							TamaFlag[i] = 1;
							shotTimer = 1;
							tCount[i] = 0;

							break;
						}
					}
				}
			}
		}

	}
	else
	{
		shotTimer++;
		if (shotTimer > 10)
		{
			//発射出来る状態
			shotTimer = 0;
		}
	}
}


void GameScene::MidiumTamaBorn()//中型艦との当たり判定
{
	if (shotTimer == 0)
	{
		for (int t = 0; t < 40; t++)
		{
			if (midiumEnemyFlag[t] == 1)
			{
				//プレイヤーと中型艦の座標が近ければ撃つ
				float dx = abs(MidiumX[t] - playerX);
				float dy = abs(MidiumY[t] - playerY);

				if (dx < 800 && dy < 800)//実体弾射程距離
				{
					for (int i = 0; i < 100; i++)
					{
						if (TamaFlag[i] == 0)
						{
							TamaX[i] = playerX;
							TamaY[i] = playerY;

							//敵方向に向く計算
							Dir[i] = atan2(MidiumY[t] - TamaY[i], MidiumX[t] - TamaX[i]);
							Dir3[i] = Dir[i] * (180.0f / 3.14);

							//回転
							spriteTama[i]->SetRotation(Dir3[i]);

							TamaFlag[i] = 1;
							shotTimer = 1;
							tCount[i] = 0;

							break;
						}
					}
				}
			}
		}

	}
	else
	{
		shotTimer++;
		if (shotTimer > 10)
		{
			//発射出来る状態
			shotTimer = 0;
		}
	}
}

void GameScene::MiniUnitTamaBorn()
{
	if (shotTimer == 0)
	{
		for (int t = 0; t < 60; t++)
		{
			if (MiniUnitFlag[t] == 1)
			{
				//プレイヤーと中型艦の座標が近ければ撃つ
				float dx = abs(MiniUnitX[t] - playerX);
				float dy = abs(MiniUnitY[t] - playerY);

				if (dx < 800 && dy < 800)//実体弾射程距離
				{
					for (int i = 0; i < 100; i++)
					{
						if (TamaFlag[i] == 0)
						{
							TamaX[i] = playerX;
							TamaY[i] = playerY;

							//敵方向に向く計算
							Dir[i] = atan2(MiniUnitY[t] - TamaY[i], MiniUnitX[t] - TamaX[i]);
							Dir3[i] = Dir[i] * (180.0f / 3.14);

							//回転
							spriteTama[i]->SetRotation(Dir3[i]);

							TamaFlag[i] = 1;
							shotTimer = 1;
							tCount[i] = 0;

							break;
						}
					}
				}
			}
		}

	}
	else
	{
		shotTimer++;
		if (shotTimer > 10)
		{
			//発射出来る状態
			shotTimer = 0;
		}
	}
}

void GameScene::MiniUnitCollisionTama()
{
	for (int e = 0; e < 60; e++)
	{
		if (MiniUnitFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 100; b++)
			{
				if (TamaFlag[b] == 1)
				{
					float dx = abs(MiniUnitX[e] - TamaX[b]);
					float dy = abs(MiniUnitY[e] - TamaY[b]);
					if (dx < 30 && dy < 30)//50実体弾当たり判定
					{
						TamaFlag[b] = 0;
						MiniUnitHp[e] -= 1;
						if (MiniUnitHp[e] <= 0)
						{
							MiniUnitFlag[e] = 0;
						}
					}
				}
			}
		}
	}
}

//要塞の弾と小型艦の当たり判定
void GameScene::MiniUnitCollisionEitway()
{
	for (int e = 0; e < 60; e++)
	{
		if (MiniUnitFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 300; b++)
			{
				if (eitwayFlag[b] == 1)
				{
					float dx = abs(MiniUnitX[e] - EitwayX[b]);
					float dy = abs(MiniUnitY[e] - EitwayY[b]);
					if (dx < 30 && dy < 30)//50実体弾当たり判定
					{
						eitwayFlag[b] = 0;
						MiniUnitHp[e] -= 2;
						if (MiniUnitHp[e] <= 0)
						{
							MiniUnitFlag[e] = 0;
						}
					}
				}
			}
		}
	}
}

void GameScene::CollisionTama()//敵と弾の当たり判定
{
	for (int e = 0; e < 20; e++)
	{
		if (enemyFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 100; b++)
			{
				if (TamaFlag[b] == 1)
				{
					float dx = abs(BigX[e] - TamaX[b]);
					float dy = abs(BigY[e] - TamaY[b]);
					if (dx < 32 && dy < 32)//実体弾当たり判定
					{
						TamaFlag[b] = 0;
						BigHp[e] -= 1;
						if (BigHp[e] <= 0)
						{
							enemyFlag[e] = 0;

						}
					}
				}
			}
		}
	}

}

void GameScene::MidiumCollisionTama()//敵と弾の当たり判定
{
	for (int e = 0; e < 40; e++)
	{
		if (midiumEnemyFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 100; b++)
			{
				if (TamaFlag[b] == 1)
				{
					float dx = abs(MidiumX[e] - TamaX[b]);
					float dy = abs(MidiumY[e] - TamaY[b]);
					if (dx < 100 && dy < 100)//実体弾当たり判定
					{
						TamaFlag[b] = 0;
						midiumHp[e] -= 10;
						if (midiumHp[e] <= 0)
						{
							midiumEnemyFlag[e] = 0;
						}
					}
				}
			}
		}
	}

}

void GameScene::PlanetPosition()
{
	for (int i = 0; i < 20; i++)
	{
		spritePlanet[i]->SetPosition({ PlanetX[i] - mapX,PlanetY[i] - mapY });

		//中心の指定
		spritePlanet[i]->SetAnchorPoint({ 0.5,0.5 });

	}
}

void GameScene::CollosionPlanet()
{
	for (int e = 0; e < 20; e++)
	{
		if (PlanetFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 100; b++)
			{
				if (TamaFlag[b] == 1)
				{
					float dx = abs(PlanetX[e] - TamaX[b]);
					float dy = abs(PlanetY[e] - TamaY[b]);
					if (dx < 100 && dy < 100)//実体弾射程距離
					{
						TamaFlag[b] = 0;
						PlanetHp[e] -= 1.5f;
						if (PlanetHp[e] <= 0)
						{
							PlanetFlag[e] = 0;
						}
					}
				}
			}
		}
	}
}

void GameScene::PlanetBorn()
{
	if (shotTimer == 0)
	{
		for (int t = 0; t < 20; t++)
		{
			if (PlanetFlag[t] == 1)
			{
				//プレイヤーと敵の座標が近ければ撃つ
				float dx = abs(PlanetX[t] - playerX);
				float dy = abs(PlanetY[t] - playerY);

				if (dx < 800 && dy < 800)//実体弾射程距離
				{
					for (int i = 0; i < 100; i++)
					{
						if (TamaFlag[i] == 0)
						{
							for (int k = 0; k < 20; k++)
							{
								TamaX[i] = playerX;
								TamaY[i] = playerY;

								Dir[i] = atan2(PlanetY[t] - TamaY[i], PlanetX[t] - TamaX[i]);
								Dir3[i] = Dir[i] * (180.0f / 3.14);

								//回転
								spriteTama[i]->SetRotation(Dir3[i]);

								TamaFlag[i] = 1;
								shotTimer = 1;
								tCount[i] = 0;
							}
							break;
						}
					}

				}
			}
		}

	}
	else
	{
		shotTimer++;
		if (shotTimer > 10)
		{
			//発射出来る状態
			shotTimer = 0;
		}
	}
}

//衛星ビームの生成
void GameScene::EiseiBeamBorn()
{
	for (int p = 0; p < 10; p++)
	{
		if (PlanetFlag[p] == 1)
		{
			if (EiseibeamCount[p] == 0)
			{
				int dx = abs(EiseiX[p] - playerX);
				int dy = abs(EiseiY[p] - playerY);

				int dx2 = abs(EiseiX[p + 10] - playerX);
				int dy2 = abs(EiseiY[p + 10] - playerY);

				if (dx < 1800 && dy < 1800)
				{
					for (int i = 0; i < 200; i++)
					{
						if (EiseibeamFlag[i] == 0)
						{
							EiseibeamFlag[i] = 1;
							EiseibeamX[i] = EiseiX[p];
							EiseibeamY[i] = EiseiY[p];
							//if (rand() % 2 == 0)
							//{
							//	EiseibeamX[i] = EiseiX[p + 10];
							//	EiseibeamY[i] = EiseiY[p + 10];
							//}
							//敵方向に向く計算
							EiseibeamDir[i] = atan2(playerY - EiseibeamY[i], playerX - EiseibeamX[i]);
							EiseibeamDir3[i] = EiseibeamDir[i] * (180.0f / 3.14);

							EiseibeamCount[p] = 1;
							break;
						}

					}
				}
				if (dx2 < 1800 && dy2 < 1800)
				{
					for (int i = 0; i < 200; i++)
					{
						if (EiseibeamFlag[i] == 0)
						{
							EiseibeamFlag[i] = 1;
							EiseibeamX[i] = EiseiX[p + 10];
							EiseibeamY[i] = EiseiY[p + 10];
							//if (rand() % 2 == 0)
							//{
							//	EiseibeamX[i] = EiseiX[p + 10];
							//	EiseibeamY[i] = EiseiY[p + 10];
							//}
							//敵方向に向く計算
							EiseibeamDir[i] = atan2(playerY - EiseibeamY[i], playerX - EiseibeamX[i]);
							EiseibeamDir3[i] = EiseibeamDir[i] * (180.0f / 3.14);

							EiseibeamCount[p] = 1;
							break;
						}

					}
				}
			}
			else
			{
				EiseibeamCount[p]++;
				if(EiseibeamCount[p] > 100)
				{
					EiseibeamCount[p] = 0;
				}
			}
		}
	}
}
//衛星の生成
void GameScene::EiseiBorn()
{
	//for (int i = 0; i < 20; i++)
	//{
	//	EiseiFlag[i] = 1;
	//}
	
	for (int i = 0; i < 10; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			EiseiX[i] = PlanetX[i] + cos(EiseiDir[i]) * 250;
			EiseiY[i] = PlanetY[i] + sin(EiseiDir[i]) * 250;

			spriteEisei[i]->SetPosition({ EiseiX[i] - mapX,EiseiY[i] - mapY });
			spriteEisei[i]->SetSize({ 100.0f,100.0f });
			spriteEisei[i]->SetAnchorPoint({ 0.5f,0.5f });
			EiseiDir[i] += 0.01;

			//後半

			EiseiX[i + 10] = PlanetX[i] + cos(EiseiDir[i] + 3.14) * 250;//cosはX軸　300は半径
			EiseiY[i + 10] = PlanetY[i] + sin(EiseiDir[i] + 3.14) * 250;

			spriteEisei[i + 10]->SetPosition({ EiseiX[i + 10] - mapX,EiseiY[i + 10] - mapY });
			spriteEisei[i + 10]->SetSize({ 100.0f,100.0f });
			spriteEisei[i + 10]->SetAnchorPoint({ 0.5f,0.5f });
		}
	}

}

//衛星ビームの移動
void GameScene::EiseiBeamMove()
{
	for (int i = 0; i < 200; i++)
	{
		if (EiseibeamFlag[i] == 1)
		{
			EiseibeamX[i] += cos(EiseibeamDir[i]) * 30;
			EiseibeamY[i] += sin(EiseibeamDir[i]) * 30;


			spriteEiseibeam[i]->SetPosition({ EiseibeamX[i] - mapX,EiseibeamY[i] - mapY});
			spriteEiseibeam[i]->SetRotation(EiseibeamDir3[i]);
			spriteEiseibeam[i]->SetSize({ 300.0f,40.0f });
		}
	}
};

void GameScene::EiseibeamCollision()
{
	if (playerFlag == 1)
	{
		for (int f = 0; f < 200; f++)
		{
			if (EiseibeamFlag[f] == 1)
			{
				float dx = abs(playerX - EiseibeamX[f]);
				float dy = abs(playerY - EiseibeamY[f]);

				float dx2 = abs(bigunitX - EiseibeamX[f]);
				float dy2 = abs(bigunitY - EiseibeamY[f]);
				if (dx < 64 && dy < 64) //当たり判定
				{
					playerHp -= 40;

					if (playerHp <= 0)
					{
						playerFlag = 0;
					}
				}
				if (bigunitFlag == 1)
				{
					if (dx2 < 248 && dy2 < 248) //当たり判定
					{
						bigunitHp -= 2;
						EiseibeamFlag[f] = 0;

						if (bigunitHp <= 0)
						{
							bigunitFlag = 0;
						}
					}
				}
			}
		}
	}
}

void GameScene::MissileBorn()
{
	for (int t = 0; t < 20; t++)
	{
		if (enemyFlag[t] == 1)
		{
			if (BigMisoTimer[t] == 0)
			{
				float dx = abs(BigX[t] - playerX);
				float dy = abs(BigY[t] - playerY);

				for (int m = 0; m < 100; m++)
				{
					if (dx > MisoRangeX && dy > MisoRangeY)//ミサイル射程
					{
						if (MissileFlag[m] == 0)
						{
							MissileX[m] = BigX[t];
							MissileY[m] = BigY[t];

							mDir[m] = atan2(playerY - MissileY[m], playerX - MissileX[m]);
							mDir3[m] = mDir[m] * (180.0f / 3.14);

							//中心点
							spriteMissile[m]->SetAnchorPoint({ 0.5f,0.5f });
							//回転
							spriteMissile[m]->SetRotation(mDir3[m]);

							MissileFlag[m] = 1;
							formingFlag[m] = 1;
							BigMisoTimer[t] = 1;
							misoTimer[m] = 0;//ミサイルタイマー

							break;
						}

					}
				}
			}
			else
			{
				BigMisoTimer[t] += 1;
				if (BigMisoTimer[t] > 800)//ミサイル生成速度
				{
					BigMisoTimer[t] = 0;
				}
			}

		}
	}
}

void GameScene::MissileMove()
{
	for (int m = 0; m < 100; m++)
	{
		if (MissileFlag[m] == 1)
		{
			float dx = abs(MissileX[m] - playerX);
			float dy = abs(MissileY[m] - playerY);
			if (dx < 150 && dy < 150)//ホーミングを外す距離
			{
				formingFlag[m] = 0;
			}
			else
			{
				if (formingFlag[m] == 1)
				{
					mDir[m] = atan2(playerY - MissileY[m], playerX - MissileX[m]);
					mDir3[m] = mDir[m] * (180.0f / 3.14);
				}
			}

			//中心点
			spriteMissile[m]->SetAnchorPoint({ 0.5f,0.5f });
			//回転
			spriteMissile[m]->SetRotation(mDir3[m]);

			MissileX[m] += cos(mDir[m]) * 15;//ミサイル速度
			MissileY[m] += sin(mDir[m]) * 15;//missile速度

			//弾座標
			spriteMissile[m]->SetPosition({ MissileX[m] - mapX, MissileY[m] - mapY });
			misoTimer[m] += 1;
			if (misoTimer[m] > 1600)
			{
				MissileFlag[m] = 0;
			}
		}
	}

}

void GameScene::PlayerCollision()
{
	if (playerFlag == 1)//存在したら
	{
		for (int b = 0; b < 100; b++)
		{
			if (MissileFlag[b] == 1)
			{
				float dx = abs(playerX - MissileX[b]);
				float dy = abs(playerY - MissileY[b]);
				float dx2 = abs(bigunitX - MissileX[b]);
				float dy2 = abs(bigunitY - MissileY[b]);
				
				if (dx < 60 && dy < 60) //当たり判定
				{
					MissileFlag[b] = 0;
					playerHp -= 50;

					if (explosionFlag[b] == 0)
					{
						explosionFlag[b] = 1;
						explosionTimer[b] = 0;
						exX[b] = MissileX[b];
						exY[b] = MissileY[b];
						break;
					}

					if (playerHp <= 0)
					{
						playerFlag = 0;
					}

				}
				if (bigunitFlag == 1)
				{
					if (dx2 < 120 && dy2 < 120) //当たり判定
					{
						MissileFlag[b] = 0;
						bigunitHp -= 5;

						if (explosionFlag[b] == 0)
						{
							explosionFlag[b] = 1;
							explosionTimer[b] = 0;
							exX[b] = MissileX[b];
							exY[b] = MissileY[b];
							break;
						}

						if (bigunitHp <= 0)
						{
							bigunitFlag = 0;
						}

					}
				}

			}


		}

	}
}

void GameScene::FivewayCollision()
{
	if (playerFlag == 1)
	{
		for (int f = 0; f < 300; f++)
		{
			if (fivewayFlag[f] == 1)
			{
				float dx = abs(playerX - fivewayX[f]);
				float dy = abs(playerY - fivewayY[f]);
				float dx2 = abs(bigunitX - fivewayX[f]);
				float dy2 = abs(bigunitY - fivewayY[f]);
				if (dx < 60 && dy < 60) //当たり判定
				{

					fivewayFlag[f] = 0;
					playerHp -= 5;

					if (playerHp <= 0)
					{
						playerFlag = 0;
					}

					for (int b = 0; b < 100; b++)
					{
						if (miniexplosionFlag[b] == 0)
						{
							miniexplosionFlag[b] = 1;
							miniexplosionTimer[b] = 0;
							miniexX[b] = fivewayX[f];
							miniexY[b] = fivewayY[f];
							break;
						}
					}


				}

				if (bigunitFlag == 1)
				{
					if (dx2 < 128 && dy2 < 128) //当たり判定
					{

						fivewayFlag[f] = 0;
						bigunitHp -= 1;

						if (bigunitHp <= 0)
						{
							bigunitFlag = 0;
						}

						for (int b = 0; b < 100; b++)
						{
							if (miniexplosionFlag[b] == 0)
							{
								miniexplosionFlag[b] = 1;
								miniexplosionTimer[b] = 0;
								miniexX[b] = fivewayX[f];
								miniexY[b] = fivewayY[f];
								break;
							}
						}


					}
				}
			}
		}
	}
}

void GameScene::AhatoCollision()
{
	if (playerFlag == 1)
	{
		for (int f = 0; f < 100; f++)
		{
			if (AhatoTamaFlag[f] == 1)
			{
				float dx = abs(playerX - AhatoTamaX[f]);
				float dy = abs(playerY - AhatoTamaY[f]);

				float dx2 = abs(bigunitX - AhatoTamaX[f]);
				float dy2 = abs(bigunitY - AhatoTamaY[f]);
				if (dx < 64 && dy < 64) //当たり判定
				{
					AhatoTamaFlag[f] = 0;
					playerHp -= 100;

					if (playerHp <= 0)
					{
						playerFlag = 0;
					}

					for (int b = 0; b < 100; b++)
					{
						if (miniexplosionFlag[b] == 0)
						{
							miniexplosionFlag[b] = 1;
							miniexplosionTimer[b] = 0;
							miniexX[b] = AhatoTamaX[f];
							miniexY[b] = AhatoTamaY[f];
							break;
						}
					}
				}
				if (bigunitFlag == 1)
				{
					if (dx2 < 128 && dy2 < 128) //当たり判定
					{
						AhatoTamaFlag[f] = 0;
						bigunitHp -= 2;

						if (bigunitHp <= 0)
						{
							bigunitFlag = 0;
						}

						for (int b = 0; b < 100; b++)
						{
							if (miniexplosionFlag[b] == 0)
							{
								miniexplosionFlag[b] = 1;
								miniexplosionTimer[b] = 0;
								miniexX[b] = AhatoTamaX[f];
								miniexY[b] = AhatoTamaY[f];
								break;
							}
						}
					}
				}
			}
		}
	}
}

void GameScene::ThreewayCollision()
{
	if (playerFlag == 1)
	{
		for (int f = 0; f < 300; f++)
		{
			if (threewayFlag[f] == 1)
			{
				float dx = abs(playerX - threewayX[f]);
				float dy = abs(playerY - threewayY[f]);

				float dx2 = abs(bigunitX - threewayX[f]);
				float dy2 = abs(bigunitY - threewayY[f]);
				if (dx < 64 && dy < 64) //当たり判定
				{
					threewayFlag[f] = 0;
					playerHp -= 1;

					if (playerHp <= 0)
					{
						playerFlag = 0;
					}

					for (int b = 0; b < 100; b++)
					{
						if (miniexplosionFlag[b] == 0)
						{
							miniexplosionFlag[b] = 1;
							miniexplosionTimer[b] = 0;
							miniexX[b] = threewayX[f];
							miniexY[b] = threewayY[f];
							break;
						}
					}
				}
				if (bigunitFlag == 1)
				{
					if (dx2 < 128 && dy2 < 128) //当たり判定
					{
						threewayFlag[f] = 0;
						bigunitHp -= 1;

						if (bigunitHp <= 0)
						{
							bigunitFlag = 0;
						}

						for (int b = 0; b < 100; b++)
						{
							if (miniexplosionFlag[b] == 0)
							{
								miniexplosionFlag[b] = 1;
								miniexplosionTimer[b] = 0;
								miniexX[b] = threewayX[f];
								miniexY[b] = threewayY[f];
								break;
							}
						}
					}
				}
			}
		}
	}
}

//HPバー（HPバーの生成）
void GameScene::HpbarBorn()
{
	for (int e = 0; e < 20; e++)
	{
		if (enemyFlag[e] == 1)
		{
			spriteHpbarGreen[e]->SetPosition({ BigX[e] - mapX, (BigY[e] - mapY) - 100 });

		}
	}
	/*for (int e = 0; e < 10; e++)
	{
		if (enemyFlag[e + 10] == 1)
		{
			spriteHpbarGreen[e + 10]->SetPosition({ BigX[e + 10] - mapX, (BigY[e + 10] - mapY) - 100 });

		}
	}*/
}

//HPバー(中型艦用)
void GameScene::HpbarBornM()
{
	for (int e = 0; e < 40; e++)
	{
		if (midiumEnemyFlag[e] == 1)
		{
			spriteHpbarMidium[e]->SetPosition({ MidiumX[e] - mapX, (MidiumY[e] - mapY) - 100 });

		}
	}
}
//HPバー（要塞）
void GameScene::HpbarBornBigUnit()
{
	if (bigunitFlag == 1)
	{
		spriteHpbarYousai->SetPosition({ (bigunitX - mapX)-100, (bigunitY - mapY)});
		spriteHpbarYousai->SetAnchorPoint({ 0.0f, 0.0f });
	}
}

//HPバー（惑星用）
void GameScene::HpbarBornPlanet()
{
	for (int e = 0; e < 20; e++)
	{
		if (PlanetFlag[e] == 1)
		{
			spritePlanetHpbar[e]->SetPosition({ PlanetX[e] - mapX - 128, (PlanetY[e] - mapY - 128)});//128は画像サイズの半分
			spritePlanetHpbar[e]->SetAnchorPoint({ 0.0f, 0.0f });
		}
	}
}

//プレイヤーキャラのHPバー
void GameScene::HpbarBornPlayer()
{
	if (playerFlag == 1)
	{
		spritePlayerHpbar->SetPosition({ playerX - mapX - 64, (playerY - mapY - 80) });//128は画像サイズの半分
		spritePlayerHpbar->SetAnchorPoint({ 0.0f, 0.0f });
	}
}

void GameScene::ExplosionBorn()
{
	for (int e = 0; e < 100; e++)
	{
		if (explosionFlag[e] == 1)
		{
			//爆発の座標
			spriteExplosion[e]->SetPosition({ exX[e] - mapX, exY[e] - mapY });
			spriteExplosion[e]->SetAnchorPoint({ 0.5f, 0.5f });

			explosionTimer[e]++;
			if (explosionTimer[e] > 30)
			{
				explosionFlag[e] = 0;
				explosionTimer[e] = 0;
				break;
			}
		}
	}
}

void GameScene::FivewayBorn()
{
	for (int t = 0; t < 20; t++)
	{
		if (enemyFlag[t] == 1)
		{
			if (BigWayTimer[t] == 0)
			{
				float dx = abs(BigX[t] - playerX);
				float dy = abs(BigY[t] - playerY);
				float dx2 = abs(BigX[t] - bigunitX);
				float dy2 = abs(BigY[t] - bigunitY);

				for (int i = 0; i < 5; i++)
				{
					for (int m = 0; m < 300; m++)
					{
						if (dx < 700 && dy < 700)//射程
						{
							if (fivewayFlag[m] == 0)
							{
								fivewayX[m] = BigX[t];
								fivewayY[m] = BigY[t];

								fDir[m] = atan2(playerY - fivewayY[m], playerX - fivewayX[m]);
								fDir[m] += ((float)i + -2) / 10;
								fDir3[m] = fDir[m] * (180.0f / 3.14);

								//中心点
								spriteFiveway[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteFiveway[m]->SetRotation(fDir3[m]);

								fivewayFlag[m] = 1;
								waytimer[m] = 1;
								BigWayTimer[t] = 1;
								fivewayTimer[m] = 0;


								break;
							}

						}
						if (dx2 < 700 && dy2 < 700)//射程
						{
							if (fivewayFlag[m] == 0)
							{
								fivewayX[m] = BigX[t];
								fivewayY[m] = BigY[t];

								fDir[m] = atan2(bigunitY - fivewayY[m], bigunitX - fivewayX[m]);
								fDir[m] += ((float)i + -2) / 10;
								fDir3[m] = fDir[m] * (180.0f / 3.14);

								//中心点
								spriteFiveway[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteFiveway[m]->SetRotation(fDir3[m]);

								fivewayFlag[m] = 1;
								waytimer[m] = 1;
								BigWayTimer[t] = 1;
								fivewayTimer[m] = 0;


								break;
							}

						}
					}
				}

			}
			else
			{
				BigWayTimer[t] += 1;
				if (BigWayTimer[t] > 10)//5way生成速度
				{
					BigWayTimer[t] = 0;
				}
			}

		}
	}
}

void GameScene::ThreewayBorn()
{
	for (int t = 0; t < 40; t++)
	{
		if (midiumEnemyFlag[t] == 1)
		{
			if (TrayTimer[t] == 0)
			{
				float dx = abs(MidiumX[t] - playerX);
				float dy = abs(MidiumY[t] - playerY);
				float dx2 = abs(MidiumX[t] - bigunitX);
				float dy2 = abs(MidiumY[t] - bigunitY);

				for (int i = 0; i < 3; i++)
				{
					for (int m = 0; m < 300; m++)
					{
						if (dx < 1500 && dy < 1500)//射程
						{
							if (threewayFlag[m] == 0)
							{
								threewayX[m] = MidiumX[t];
								threewayY[m] = MidiumY[t];

								tDir[m] = atan2(playerY - threewayY[m], playerX - threewayX[m]);
								tDir[m] += ((float)i + -2) / 12;
								tDir3[m] = tDir[m] * (180.0f / 3.14);

								//中心点
								spriteFiveway[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteFiveway[m]->SetRotation(tDir3[m]);

								threewayFlag[m] = 1;
								threewaytimer[m] = 1;
								TrayTimer[t] = 1;
								threewayTimer[m] = 0;


								break;
							}

						}
						if (dx2 < 1500 && dy2 < 1500)//射程
						{
							if (threewayFlag[m] == 0)
							{
								threewayX[m] = MidiumX[t];
								threewayY[m] = MidiumY[t];

								tDir[m] = atan2(bigunitY - threewayY[m], bigunitX - threewayX[m]);
								tDir[m] += ((float)i + -2) / 12;
								tDir3[m] = tDir[m] * (180.0f / 3.14);

								//中心点
								spriteFiveway[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteFiveway[m]->SetRotation(tDir3[m]);

								threewayFlag[m] = 1;
								threewaytimer[m] = 1;
								TrayTimer[t] = 1;
								threewayTimer[m] = 0;


								break;
							}

						}
					}
				}

			}
			else
			{
				TrayTimer[t] += 1;
				if (TrayTimer[t] > 5)//5way生成速度
				{
					TrayTimer[t] = 0;
				}
			}

		}
	}
}

void GameScene::FivewayMove()
{
	for (int m = 0; m < 300; m++)
	{
		if (fivewayFlag[m] == 1)
		{
			//float dx = abs(fivewayX[m] - playerX);
			//float dy = abs(fivewayY[m] - playerY);

			//中心点
			spriteFiveway[m]->SetAnchorPoint({ 0.5f,0.5f });
			//回転
			spriteFiveway[m]->SetRotation(fDir3[m]);

			//当たり判定が不明

			fivewayX[m] += cos(fDir[m]) * 12;//5way速度
			fivewayY[m] += sin(fDir[m]) * 12;//5way速度
			//弾座標
			spriteFiveway[m]->SetPosition({ fivewayX[m] - mapX, fivewayY[m] - mapY });

			fivewayTimer[m] += 1;
			if (fivewayTimer[m] > 150)
			{
				fivewayFlag[m] = 0;
			}
		}
	}
}

void GameScene::ThreewayMove()
{
	for (int m = 0; m < 300; m++)
	{
		if (threewayFlag[m] == 1)
		{
			//float dx = abs(fivewayX[m] - playerX);
			//float dy = abs(fivewayY[m] - playerY);

			//中心点
			spriteThreeway[m]->SetAnchorPoint({ 0.5f,0.5f });
			//回転
			spriteThreeway[m]->SetRotation(tDir3[m]);

			//当たり判定が不明

			threewayX[m] += cos(tDir[m]) * 20;//3way速度
			threewayY[m] += sin(tDir[m]) * 20;//3way速度
			//弾座標
			spriteThreeway[m]->SetPosition({ threewayX[m] - mapX, threewayY[m] - mapY });

			threewayTimer[m] += 1;
			if (threewayTimer[m] > 150)
			{
				threewayFlag[m] = 0;
			}
		}
	}
}

void GameScene::Resporn()
{
	//敵のランダム生成
	for (int i = 0; i < 10; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			if (enemyFlag[i] == 0)
			{
				if (RespornTimer[i] == 0)
				{
					enemyFlag[i] = 1;
					BigHp[i] = 60;

					BigX[i] = PlanetX[i];
					BigY[i] = PlanetY[i];
					RespornTimer[i] = 1000;
				}
				else
				{
					RespornTimer[i] -= 1;
				}
			}
		}

	}
	//敵のランダム生成
	for (int i = 0; i < 10; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			if (enemyFlag[i + 10] == 0)
			{
				if (RespornTimer[i + 10] == 0)
				{
					enemyFlag[i + 10] = 1;
					BigHp[i + 10] = 60;
					BigX[i + 10] = PlanetX[i];
					BigY[i + 10] = PlanetY[i];
					RespornTimer[i + 10] = 1000;
				}
				else
				{
					RespornTimer[i + 10] -= 1;
				}
			}
		}

	}

	//中型艦のランダム生成
	for (int i = 0; i < 40; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			if (midiumEnemyFlag[i] == 0)
			{
				if (MidiumRespornTimer[i] == 0)
				{
					midiumEnemyFlag[i] = 1;
					midiumHp[i] = 20;

					MidiumX[i] = PlanetX[i];
					MidiumY[i] = PlanetY[i];
					MidiumRespornTimer[i] = 500;
				}
				else
				{
					MidiumRespornTimer[i] -= 1;
				}
			}
		}

	}

	if (bigunitFlag == 0)
	{
		if (bigunitRespornTimer == 0)
		{
			bigunitFlag = 1;
			bigunitHp = 1500;
			bigunitX = 0;
			bigunitY = 0;
			bigunitRespornTimer = 1000;
		}
		else
		{
			bigunitRespornTimer -= 1;
		}
	}

	//小型艦のランダム生成
	for (int i = 0; i < 60; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			if (MiniUnitFlag[i] == 0)
			{
				MiniUnitFlag[i] = 1;
				MiniUnitHp[i] = 10;

				MiniUnitX[i] = PlanetX[i];
				MiniUnitY[i] = PlanetY[i];
			}
		}
	}
}

//的中型艦の生成
void GameScene::MidiumEnemyBorn()
{
	for (int m = 0; m < 40; m++)
	{
		if (midiumEnemyFlag[m] == 1)
		{
			spriteMidiumEnemy[m]->SetPosition({ MidiumX[m] - mapX ,MidiumY[m] - mapY });
			//プレイヤー方向へ向く計算
			float Dir = atan2(playerY - MidiumY[m], playerX - MidiumX[m]);
			float Dir2 = Dir * (180.0f / 3.14);

			//中心の指定
			spriteMidiumEnemy[m]->SetAnchorPoint({ 0.5,0.5 });
			//回転
			spriteMidiumEnemy[m]->SetRotation(Dir2);
		}
	}


}

//中型艦移動処理
void GameScene::MidiumEnemyMove()
{
	for (int m = 0; m < 40; m++)
	{
		if (midiumEnemyFlag[m] == 1)
		{
			if (playerX - 800 > MidiumX[m])
			{
				MidiumX[m] += 6;
			}

			if (playerX + 800 < MidiumX[m])
			{
				MidiumX[m] -= 6;
			}

			if (playerY - 800 > MidiumY[m])
			{
				MidiumY[m] += 6;
			}
			if (playerY + 800 < MidiumY[m])
			{
				MidiumY[m] -= 6;
			}
		}
	}
}

void GameScene::MiniEnemyBorn()
{
	for (int m = 0; m < 60; m++)
	{
		if (MiniUnitFlag[m] == 1)
		{
			spriteKogataEnemy[m]->SetPosition({ MiniUnitX[m] - mapX ,MiniUnitY[m] - mapY });
			//プレイヤー方向へ向く計算
			float Dir = atan2(playerY - MiniUnitY[m], playerX - MiniUnitX[m]);
			float Dir2 = Dir * (180.0f / 3.14);

			//サイズ
			spriteKogataEnemy[m]->SetSize({ 100 , 100 });
			//中心の指定
			spriteKogataEnemy[m]->SetAnchorPoint({ 0.5,0.5 });
			//回転
			spriteKogataEnemy[m]->SetRotation(Dir2);
		}
	}
}

void GameScene::MiniEnemyMove()
{
	for (int m = 0; m < 60; m++)
	{
		if (MiniUnitFlag[m] == 1)
		{
			float shatei = 400;

			if (playerX - shatei > MiniUnitX[m])
			{
				MiniUnitX[m] += 8;
			}

			if (playerX + shatei < MiniUnitX[m])
			{
				MiniUnitX[m] -= 8;
			}

			if (playerY - shatei > MiniUnitY[m])
			{
				MiniUnitY[m] += 8;
			}
			if (playerY + shatei < MiniUnitY[m])
			{
				MiniUnitY[m] -= 8;
			}
		}
	}
}

void GameScene::MiniExplosionBorn()
{
	for (int e = 0; e < 100; e++)
	{
		if (miniexplosionFlag[e] == 1)
		{

			//爆発の座標
			spriteMiniExplosion[e]->SetPosition({ miniexX[e] - mapX, miniexY[e] - mapY });
			spriteMiniExplosion[e]->SetAnchorPoint({ 0.5f, 0.5f });

			miniexplosionTimer[e]++;
			if (miniexplosionTimer[e] > 15)
			{
				miniexplosionFlag[e] = 0;
				miniexplosionTimer[e] = 0;
				break;
			}

		}
	}
}

//味方基地移動
void GameScene::BigUnitMove()
{
	//敵座標
	if (bigunitFlag == 1)
	{
		//TargetX,Yはどの敵の座評なのかを代入する値
		float TargetX = 0;
		float TargetY = 0;
		//一番近い敵を出すための距離
		float kyori2 = 40000;
		//目標を決める
		for (int i = 0; i < 20; i++)
		{

			//敵ユニットへ向かう移動処理
			if (enemyFlag[i] == 1)//目標となる敵が存在していたら
			{
				float dx = abs(BigX[i] - bigunitX);//距離を求める
				float dy = abs(BigY[i] - bigunitY);//同じ
				float kyori = dx + dy;//距離を合計する
				if (kyori < kyori2)//kyori=暫定の距離よりも小さかったら <kyori2=暫定の距離
				{
					TargetX = BigX[i];
					TargetY = BigY[i];
					kyori2 = kyori;//今までで一番近い敵を出す
				}

			
			}

		}

		//移動処理
		bDir = atan2(TargetY - bigunitY, TargetX - bigunitX);
		bDir2 = bDir * (180.0f / 3.14);
		if (kyori2 > 2000)
		{
			bigunitX += cos(bDir) * 8;//8way速度
			bigunitY += sin(bDir) * 8;//8way速度
		}
		//中心点
		spriteBigUnit->SetAnchorPoint({ 0.5f,0.5f });
		//回転
		spriteBigUnit->SetRotation(bDir2);

		spriteBigUnit->SetPosition({ bigunitX - mapX ,bigunitY - mapY });
	}

}

void GameScene::BigUnitEitwayBorn()
{

	//一番近い敵を選択
	int haniT;
	int k;//Kは大きい値
	int enemyType;//敵の種類

	//大型艦用
	k = 9999;
	for (int i = 0; i < 20; i++)
	{

		float dx = abs(bigunitX - BigX[i]);
		float dy = abs(bigunitY - BigY[i]);

		if (enemyFlag[i] == 1)
		{
			if (dx < 2000 && dy < 2000)//射程
			{
				int k2 = dx + dy;
				if (k2 < k)
				{
					k = k2;//距離を更新
					haniT = i;//何番目の敵かを記録
					enemyType = 0;
				}
			}
		}
	}

	//中型艦用
	for (int i = 0; i < 20; i++)
	{

		float dx = abs(bigunitX - MidiumX[i]);
		float dy = abs(bigunitY - MidiumY[i]);

		if (midiumEnemyFlag[i] == 1)
		{
			if (dx < 2000 && dy < 2000)//射程
			{
				int k2 = dx + dy;
				if (k2 < k)
				{
					k = k2;//距離を更新
					haniT = i;//何番目の敵かを記録
					enemyType = 1;
				}
			}
		}
	}

	//小型艦用
	for (int i = 0; i < 20; i++)
	{

		float dx = abs(bigunitX - MiniUnitX[i]);
		float dy = abs(bigunitY - MiniUnitY[i]);

		if (MiniUnitFlag[i] == 1)
		{
			if (dx < 2000 && dy < 2000)//射程
			{
				int k2 = dx + dy;
				if (k2 < k)
				{
					k = k2;//距離を更新
					haniT = i;//何番目の敵かを記録
					enemyType = 2;
				}
			}
		}
	}

	if (k < 9999)//kが9999より小さくなったら
	{
		int t = haniT;//tに範囲Tを敵に代入

		if (bigunitFlag == 1)
		{
			if (ErayTimer[t] == 0)
			{

				float kyori2 = 40000;
				float dx;
				float dy;
				//大型艦用
				if (enemyType == 0)
				{
					 dx = abs(bigunitX - BigX[t]);
					 dy = abs(bigunitY - BigY[t]);
				}
				//中型艦用
				if (enemyType == 1)
				{
					 dx = abs(bigunitX - MidiumX[t]);
					 dy = abs(bigunitY - MidiumY[t]);
				}
				//小型艦用
				if (enemyType == 2)
				{
					 dx = abs(bigunitX - MiniUnitX[t]);
					 dy = abs(bigunitY - MiniUnitY[t]);
				}
				float kyori = dx + dy;

				if (kyori < kyori2)
				{
					for (int k = 0; k < 4; k++)
					{
						for (int i = 0; i < 7; i++)//8way
						{
							for (int m = 0; m < 300; m++)
							{
								if (eitwayFlag[m] == 0)
								{
									if (k == 0)
									{
										EitwayX[m] = bigunitX + 100;
										EitwayY[m] = bigunitY;
									}
									if (k == 1)
									{
										EitwayX[m] = bigunitX - 100;
										EitwayY[m] = bigunitY;
									}
									if (k == 2)
									{
										EitwayX[m] = bigunitX;
										EitwayY[m] = bigunitY + 100;
									}
									if (k == 3)
									{
										EitwayX[m] = bigunitX;
										EitwayY[m] = bigunitY - 100;
									}


									eDir[m] = atan2(BigY[t] - EitwayY[m], BigX[t] - EitwayX[m]);

									eDir[m] += ((float)i + -2) / 10;
									eDir3[m] = eDir[m] * (180.0f / 3.14);

									//中心点
									spriteEitway[m]->SetAnchorPoint({ 0.5f,0.5f });
									//回転
									spriteEitway[m]->SetRotation(eDir3[m]);

									eitwayFlag[m] = 1;
									ErayTimer[t] = 1;
									EitWayTimer[m] = 1;
									eitwayTimer[m] = 0;
									break;
								}
							}

						}
					}
				}

			}
			else
			{
				ErayTimer[t] += 1;
				if (ErayTimer[t] > 30)//5way生成速度
				{
					ErayTimer[t] = 0;
				}
			}
		}

	}
}

//プレイヤーと小型艦の弾
void GameScene::AhatoTamaBorn()
{
	for (int t = 0; t < 60; t++)
	{
		if (MiniUnitFlag[t] == 1)
		{
			if (AhatoWayTimer[t] == 0)//連射カウント（連発防止）
			{
				float dx = abs(MiniUnitX[t] - playerX);
				float dy = abs(MiniUnitY[t] - playerY);
				float dx2 = abs(MiniUnitX[t] - bigunitX);
				float dy2 = abs(MiniUnitY[t] - bigunitY);

				//for (int i = 0; i < 3; i++)
				{
					for (int m = 0; m < 100; m++)
					{
						if (dx < 2500 && dy < 2500)//射程
						{
							if (AhatoTamaFlag[m] == 0)
							{
								AhatoTamaX[m] = MiniUnitX[t];
								AhatoTamaY[m] = MiniUnitY[t];

								AhatoDir[m] = atan2(playerY - AhatoTamaY[m], playerX - AhatoTamaX[m]);
								//AhatoDir[m] += ((float)i + -2) / 12;
								AhatoDir3[m] = AhatoDir[m] * (180.0f / 3.14);

								//中心点
								spriteAHATO[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteAHATO[m]->SetRotation(AhatoDir3[m]);

								AhatoTamaFlag[m] = 1;
								AhatoWayTimer[t] = 1;
								AhatoRayTimer[m] = 0;
								ahatoRayTimer[m] = 1;
								AhatoCount[m] = 0;

								break;
							}

						}
						if (dx2 < 2500 && dy2 < 2500)//射程
						{
							if (AhatoTamaFlag[m] == 0)
							{
								AhatoTamaX[m] = MiniUnitX[t];
								AhatoTamaY[m] = MiniUnitY[t];

								AhatoDir[m] = atan2(bigunitY - AhatoTamaY[m], bigunitX - AhatoTamaX[m]);
								//AhatoDir[m] += ((float)i + -2) / 12;
								AhatoDir3[m] = AhatoDir[m] * (180.0f / 3.14);

								//中心点
								spriteAHATO[m]->SetAnchorPoint({ 0.5f,0.5f });
								//回転
								spriteAHATO[m]->SetRotation(AhatoDir3[m]);

								AhatoTamaFlag[m] = 1;
								AhatoRayTimer[m] = 1;
								AhatoWayTimer[t] = 1;//連射カウント
								ahatoRayTimer[m] = 1;
								AhatoCount[m] = 0;

								break;
							}

						}
					}
				}

			}
			else
			{
				AhatoWayTimer[t] += 1;//連射カウント
				if (AhatoWayTimer[t] > 150)//生成速度
				{
					AhatoWayTimer[t] = 0;
				}
			}

		}
	}
}


void GameScene::BigUnitEitwayMove()
{
	for (int m = 0; m < 300; m++)
	{
		if (eitwayFlag[m] == 1)
		{
			//float dx = abs(fivewayX[m] - playerX);
			//float dy = abs(fivewayY[m] - playerY);

			//中心点
			spriteEitway[m]->SetAnchorPoint({ 0.5f,0.5f });
			//回転
			spriteEitway[m]->SetRotation(eDir3[m]);

			//当たり判定が不明

			EitwayX[m] += cos(eDir[m]) * 25;//8way速度
			EitwayY[m] += sin(eDir[m]) * 25;//8way速度
			//弾座標
			spriteEitway[m]->SetPosition({ EitwayX[m] - mapX, EitwayY[m] - mapY });

			eitwayTimer[m] += 1;
			if (eitwayTimer[m] > 150)
			{
				eitwayFlag[m] = 0;
			}
		}

	}
}

void GameScene::DrawMiniMap()
{
	spriteMiniPlayer->SetPosition({ playerX / 100 - 130 ,playerY / 100 - 72});
	for (int p = 0; p < 20; p++)
	{
		
		spriteMiniPlanet[p]->SetPosition({ PlanetX[p] / 100,PlanetY[p] / 100 });
		spriteMiniEnemy[p]->SetPosition({ BigX[p] / 100,BigY[p] / 100 });
		spriteMiniUnit[p]->SetPosition({ MiniUnitX[p] / 100,MiniUnitY[p] / 100 });
		spriteYousai->SetPosition({ bigunitX / 100,bigunitY / 100 });
		for (int m = 0; m < 40; m++)
		{
			spriteMiniNormalEnemy[m]->SetPosition({ MidiumX[m] / 100,MidiumY[m] / 100});
		}
		for (int s = 0; s < 100; s++)
		{
			spriteMiniMiss[s]->SetPosition({ MissileX[s] / 100,MissileY[s] / 100 });
		}
	}
}

void GameScene::EitwayCollision()
{
	for (int e = 0; e < 20; e++)
	{
		if (enemyFlag[e] == 1)//存在したら
		{
			for (int b = 0; b < 300; b++)
			{
				if (eitwayFlag[b] == 1)
				{
					float dx = abs(BigX[e] - EitwayX[b]);
					float dy = abs(BigY[e] - EitwayY[b]);

					float dx2 = abs(MidiumX[e] - EitwayX[b]);
					float dy2 = abs(MidiumY[e] - EitwayY[b]);

					float dx3 = abs(MiniUnitX[e] - EitwayX[b]);
					float dy3 = abs(MiniUnitY[e] - EitwayY[b]);

					if (dx < 64 && dy < 64)//実体弾当たり判定
					{
						eitwayFlag[b] = 0;
						BigHp[e] -= 5;
						if (BigHp[e] <= 0)
						{
							enemyFlag[e] = 0;

						}
					}
					if (dx2 < 48 && dy2 < 48)//実体弾当たり判定
					{
						eitwayFlag[b] = 0;
						midiumHp[e] -= 5;
						if (midiumHp[e] <= 0)
						{
							midiumEnemyFlag[e] = 0;
						}
					}
					if (dx3 < 30 && dy3 < 30)
					{
						eitwayFlag[b] = 0;
						MiniUnitHp[e] -= 5;
						if (MiniUnitHp[e] <= 0)
						{
							MiniUnitFlag[e] = 0;
						}
					}

				}
			}
		}
	}
}

void GameScene::GamePlayUpdate()
{
	DrawMiniMap();//ミニマップ
	TamaBorn();//弾生成
	PlanetBorn();//惑星と弾の処理
	MissileBorn();//ミサイル生成
	FivewayBorn();//５wayの生成
	AhatoTamaBorn();//弾生成
	Resporn();
	MiniEnemyBorn();//敵小型艦
	MidiumEnemyBorn();//敵中型艦
	MiniUnitTamaBorn();//小型艦とプレイヤー弾の当たり判定
	MidiumTamaBorn();
	ThreewayBorn();//３way生成
	EiseiBorn();//戦闘衛星生成
	EiseiBeamBorn();//戦闘衛星ビーム生成
	HpbarBorn();//HPバーの生成
	HpbarBornM();//HPバーの生成中型艦用
	HpbarBornBigUnit();//要塞のHPバー
	HpbarBornPlayer();//プレイヤーのhpバー
	HpbarBornPlanet();//惑星のHPバー

	BigUnitEitwayBorn();//味方基地用８way弾
	AhatoTamaMove();//弾移動
	PlayerMove();//プレイヤー移動
	MiniUnitMove();//味方小型艦移動
	BigenemyMove();//敵大型艦移動処理
	FivewayMove();//５wayの動き
	EiseiBeamMove();//戦闘衛星ビーム移動
	TamaMove();//弾移動処理
	MissileMove();//ミサイル移動
	MidiumEnemyMove();//敵中型艦移動
	MiniEnemyMove();//敵小型艦
	ThreewayMove();//3way移動
	BigUnitMove();//味方基地移動
	BigUnitEitwayMove();//味方基地用8way弾
	PlanetPosition();//惑星の位置

	CollisionTama();//弾と敵の当たり判定
	CollosionPlanet();//惑星と弾の当たり判定
	PlayerCollision();//プレイヤーとミサイルの当たり判定
	FivewayCollision();
	ThreewayCollision();//3wayの当たり判定
	ExplosionBorn();//爆発の位置設定
	MiniExplosionBorn();//mini爆発の位置設定
	MidiumCollisionTama();//中型艦とプレイヤー弾の当たり判定
	MiniUnitCollisionTama();//小型艦とプレイヤー弾の当たり判定
	EitwayCollision();//８連射当たり判定
	AhatoCollision();//小型艦単発弾当たり判定
	MiniUnitCollisionEitway();//要塞の弾と敵小型艦の当たり判定
	EiseibeamCollision();//衛星ビームとプレイヤーの当たり判定

	object3d->Update();

	if (playerFlag == 0)
	{
		sceneMode = 2;
	}

	int total = 0;

	for (int i = 0; i < 10; i++)
	{
		if (PlanetFlag[i] == 0)
		{
			total++;
		}
	}

	if (total == 10)
	{
		sceneMode = 3;
	}
}

void GameScene::GamePlayDraw3D()
{
	//背景スプライト位置
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			spriteBG[y][x]->SetPosition({ x * 1280 - mapX, y * 720 - mapY });
		}
	}

	// 背景スプライト描画
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			spriteBG[y][x]->Draw();
		}
	}

	//惑星描画
	for (int i = 0; i < 20; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			spritePlanet[i]->Draw();

		}
	}

	//戦闘衛星
	for (int i = 0; i < 10; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			spriteEisei[i]->Draw();
			spriteEisei[i + 10]->Draw();
		}
	}

	//プレイヤースプライト描画
	if (playerFlag == 1)
	{
		if (playerTimer % 20 < 10)
		{
			spritePlayerTenmetu->Draw();
		}
		else
		{
			spritePlayer->Draw();
		}
	}

	//味方小型艦描画
	for (int i = 0; i < 10; i++)
	{
		if (kogataMikataFlag[i] == 1)
		{
			spriteKogataUnit[i]->Draw();
		}
	}

	//味方基地描画
	if (bigunitFlag == 1)
	{
		if (bigunitFlag == 1);
		{
			spriteBigUnit->Draw();
		}
	}

	//エネミースプライト描画
	for (int i = 0; i < 20; i++)
	{
		if (enemyFlag[i] == 1)
		{
			spriteBigenemy[i]->Draw();
		}
	}

	//中型艦描画
	for (int i = 0; i < 40; i++)
	{
		if (midiumEnemyFlag[i] == 1)
		{
			spriteMidiumEnemy[i]->Draw();
		}
	}

	//小型艦描画
	for (int i = 0; i < 60; i++)
	{
		if (MiniUnitFlag[i] == 1)
		{
			spriteKogataEnemy[i]->Draw();
		}
	}


	//実体弾描画
	if (playerFlag == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (TamaFlag[i] == 1)
			{
				spriteTama[i]->Draw();
			}
		}
	}

	//実体弾描画
	for (int i = 0; i < 100; i++)
	{
		if (AhatoTamaFlag[i] == 1)
		{
			spriteAHATO[i]->Draw();
		}
	}

	//missile描画
	for (int i = 0; i < 100; i++)
	{
		if (MissileFlag[i] == 1)
		{
			spriteMissile[i]->Draw();
		}
	}

	//爆発描画
	for (int i = 0; i < 100; i++)
	{
		if (explosionFlag[i] == 1)
		{
			if (explosionTimer[i] % 4 < 2)//点滅処理（4で割った余りが２より小さかったら表示）
			{
				spriteExplosion[i]->SetSize({ 128 - explosionTimer[i] * 3.0f,128 - explosionTimer[i] * 3.0f });
				spriteExplosion[i]->Draw();
			}
		}
	}

	//mini爆発描画
	for (int i = 0; i < 100; i++)
	{
		if (miniexplosionFlag[i] == 1)
		{
			if (miniexplosionTimer[i] % 4 < 2)
			{
				spriteMiniExplosion[i]->SetSize({ 64 - miniexplosionTimer[i] * 3.0f,64 - miniexplosionTimer[i] * 3.0f });
				spriteMiniExplosion[i]->Draw();
			}
		}
	}

	//５way描画
	for (int i = 0; i < 300; i++)
	{
		if (fivewayFlag[i] == 1)
		{
			spriteFiveway[i]->Draw();
		}
	}

	//3way描画
	for (int i = 0; i < 300; i++)
	{
		if (threewayFlag[i] == 1)
		{
			spriteThreeway[i]->Draw();
		}
	}

	//戦闘衛星ビーム描画
	for (int i = 0; i < 200; i++)
	{
		if (EiseibeamFlag[i] == 1)
		{
			spriteEiseibeam[i]->Draw();
		}
	}

	//8way描画
	for (int i = 0; i < 300; i++)
	{
		if (eitwayFlag[i] == 1)
		{
			spriteEitway[i]->Draw();
		}
	}

	//大型艦HPバー描画
	for (int i = 0; i < 20; i++)
	{
		if (enemyFlag[i] == 1)
		{
			spriteHpbarGreen[i]->SetSize({ (float)BigHp[i],30 });
			spriteHpbarGreen[i]->Draw();
		}
	}

	//中型艦HPバー描画
	for (int i = 0; i < 40; i++)
	{
		if (midiumEnemyFlag[i] == 1)
		{
			spriteHpbarMidium[i]->SetSize({ (float)midiumHp[i] * 3 ,30 });
			spriteHpbarMidium[i]->Draw();
		}
	}

	//要塞HPバー描画
	if (bigunitFlag == 1)
	{
		spriteHpbarYousai->SetSize({ (float)bigunitHp / 10,30 });
		spriteHpbarYousai->Draw();
	}
	 
	//プレイヤーHPバー描画
	if (playerFlag == 1)
	{
		spritePlayerHpbar->SetSize({ (float)playerHp / 80,30 });
		spritePlayerHpbar->Draw();
	}

	//惑星HPバー描画
	for (int i = 0; i < 20; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			spritePlanetHpbar[i]->SetSize({ (float)PlanetHp[i] / 2.3f,30.0f });
			spritePlanetHpbar[i]->Draw();
		}
	}

	spriteBackMini->Draw();
	spriteYousai->Draw();
	spriteMiniPlayer->Draw();

	for (int i = 0; i < 20; i++)
	{
		if (enemyFlag[i] == 1)
		{
			spriteMiniEnemy[i]->Draw();
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if (PlanetFlag[i] == 1)
		{
			spriteMiniPlanet[i]->Draw();
		}
	}

	for (int i = 0; i < 60; i++)
	{
		if (MiniUnitFlag[i] == 1)
		{
			spriteMiniUnit[i]->Draw();
		}
	}

	for (int i = 0; i < 40; i++)
	{
		if (midiumEnemyFlag[i] == 1)
		{
			spriteMiniNormalEnemy[i]->Draw();
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (MissileFlag[i] == 1)
		{
			spriteMiniMiss[i]->Draw();
		}
	}

}


void GameScene::TitleUpdate()
{
	if (input->TriggerKey(DIK_SPACE))
	{
		GamePlayStart();
		sceneMode = 0;
	}
}

void GameScene::TitleDraw2D()
{
	spriteTitle->Draw();
}

void GameScene::OverUpdate()
{
	if (input->TriggerKey(DIK_SPACE))
	{
		sceneMode = 1;
	}
}

void GameScene::OverDraw2D()
{
	spriteOver->Draw();
}

void GameScene::ClearUpdate()
{
	if (input->TriggerKey(DIK_SPACE))
	{
		sceneMode = 1;
	}
}

void GameScene::ClearDraw2D()
{
	spriteClear->Draw();
}

void GameScene::GamePlayStart()
{

	//playerX = 640;
	//playerY = 360;

	// 背景スプライト生成
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			spriteBG[y][x] = Sprite::Create(1, { x * 1280.0f,y * 720.0f });
		}
	}
	//プレイヤーの生成
	spritePlayer = Sprite::Create(2, { 0.0f,0.0f });
	playerFlag = 1;
	playerHp = 10000;

	//味方基地の生成
	spriteBigUnit = Sprite::Create(16, { 0.0f,0.0f });
	bigunitFlag = 1;
	bigunitHp = 1500;

	//味方小型艦生成
	for (int i = 0; i < 10; i++)
	{
		spriteKogataUnit[i] = Sprite::Create(70, { 0.0f, 0.0f });
	}

	//敵中型艦生成
	for (int i = 0; i < 40; i++)
	{
		spriteMidiumEnemy[i] = Sprite::Create(13, { 0.0f, 0.0f });
	}

	//敵小型艦
	for (int i = 0; i < 60; i++)
	{
		spriteKogataEnemy[i] = Sprite::Create(38, { 0.0f,0.0f });
	}

	//敵大型艦生成
	for (int i = 0; i < 20; i++)
	{
		spriteBigenemy[i] = Sprite::Create(3, { 0.0f, 0.0f });
	}


	////敵戦闘衛星生成
	for (int i = 0; i < 20; i++)
	{
		spriteEisei[i] = Sprite::Create(32, { 0.0f, 0.0f });

	}

	//実体弾
	for (int i = 0; i < 100; i++)
	{
		spriteTama[i] = Sprite::Create(4, { 0.0f,0.0f });
	}

	//小型艦弾
	for (int i = 0; i < 100; i++)
	{
		spriteAHATO[i] = Sprite::Create(88, { 0.0f,0.0f });
		spriteAHATO[i]->SetSize({120,120 });
	}

	//惑星生成
	for (int i = 0; i < 20; i++)
	{
		spritePlanet[i] = Sprite::Create(5, { 0.0f,0.0f });
	}

	//爆発生成
	for (int i = 0; i < 100; i++)
	{
		spriteExplosion[i] = Sprite::Create(7, { 0.0f,0.0f });
	}

	//mini爆発生成
	for (int i = 0; i < 100; i++)
	{
		spriteMiniExplosion[i] = Sprite::Create(15, { 0.0f,0.0f });
	}


	//missile生成
	for (int i = 0; i < 100; i++)
	{
		spriteMissile[i] = Sprite::Create(6, { 0.0f,0.0f });
	}

	//8way生成
	for (int i = 0; i < 300; i++)
	{
		spriteEitway[i] = Sprite::Create(80, { 0.0f,0.0f });
	}

	//5way生成
	for (int i = 0; i < 300; i++)
	{
		spriteFiveway[i] = Sprite::Create(8, { 0.0f,0.0f });
	}

	//3way生成
	for (int i = 0; i < 300; i++)
	{
		spriteThreeway[i] = Sprite::Create(14, { 0.0f,0.0f });
	}

	//戦闘衛星ビーム
	for (int i = 0; i < 200; i++)
	{
		spriteEiseibeam[i] = Sprite::Create(35, { 0.0f,0.0f });
	}

	//ミニ惑星
	for (int i = 0; i < 20; i++)
	{
		spriteMiniPlanet[i] = Sprite::Create(11, { 0.0f,0.0f });
	}

	//ミニ小型艦
	for (int i = 0; i < 60; i++)
	{
		spriteMiniUnit[i] = Sprite::Create(17, { 0.0f,0.0f });
	}

	//ミニ敵
	for (int i = 0; i < 20; i++)
	{
		spriteMiniEnemy[i] = Sprite::Create(10, { 0.0f,10.0f });
	}

	//ミニ敵
	for (int i = 0; i < 40; i++)
	{
		spriteMiniNormalEnemy[i] = Sprite::Create(20, { 0.0f,10.0f });
	}

	//ミニミサイル
	for (int i = 0; i < 100; i++)
	{
		spriteMiniMiss[i] = Sprite::Create(23, { 0.0f,10.0f });
	}

	//大型艦HPバー
	for (int i = 0; i < 20; i++)
	{
		spriteHpbarGreen[i] = Sprite::Create(101, { 0.0f,0.0f });
	}

	//中型艦HPバー//spriteは別にする
	for (int i = 0; i < 40; i++)
	{
		spriteHpbarMidium[i] = Sprite::Create(101, { 0.0f,0.0f });
	}

	//惑星のHPバー
	for (int i = 0; i < 20; i++)
	{
		spritePlanetHpbar[i] = Sprite::Create(102, { 0.0f,0.0f });
	}

	//要塞のHpバー
	spriteHpbarYousai = Sprite::Create(101, { 0.0f,0.0f });

	//プレイヤーのHpバー
	spritePlayerHpbar = Sprite::Create(101, { 0.0f,0.0f });

	//ミニユニット
	spriteYousai = Sprite::Create(30, { 0.0f,0.0f });


	//ミニプレイヤー
	spriteMiniPlayer = Sprite::Create(12, { 0.0f,20.0f });

	//ミニプレイヤー
	spriteBackMini = Sprite::Create(100, { 0.0f,0.0f });

	/////シーン
	//タイトル
	spriteTitle = Sprite::Create(200, { 0.0f,0.0f });

	//ゲームオーバー
	spriteOver = Sprite::Create(201, { 0.0f,0.0f });

	//ゲームクリア
	spriteClear = Sprite::Create(202, { 0.0f,0.0f });

	//プレイヤーの初期座標
	spritePlayer->SetPosition({ 0,0 });

	// 3Dオブジェクト生成
	object3d = Object3d::Create();
	object3d->Update();

	//惑星生成
	for (int i = 0; i < 10; i++)
	{
		PlanetFlag[i] = 1;
		PlanetHp[i] = 600;

		PlanetX[i] = rand() % 25600;
		PlanetY[i] = rand() % 14400;
	}

	//敵のランダム生成
	for (int i = 0; i < 10; i++)
	{
		enemyFlag[i] = 0;
		BigHp[i] = 60;

		BigX[i] = PlanetX[i];
		BigY[i] = PlanetY[i];

		RespornTimer[i] = 1000;
	}
	for (int i = 0; i < 10; i++)
	{

		enemyFlag[i + 10] = 0;
		BigHp[i + 10] = 60;

		BigX[i + 10] = PlanetX[i];
		BigY[i + 10] = PlanetY[i];

		RespornTimer[i] = 1000;
	}
	//敵中型艦の生成
	for (int i = 0; i < 40; i++)
	{
		for (int m = 0; m < 20; m++)
		{
			midiumEnemyFlag[i] = 0;
			midiumHp[i] = 20;

			MidiumX[i] = PlanetX[m];
			MidiumY[i] = PlanetY[m];

			MidiumRespornTimer[i] = 500;
		}
	}

	//敵小型艦の生成
	for (int i = 0; i < 60; i++)
	{
		for (int m = 0; m < 20; m++)
		{
			MiniUnitFlag[i] = 0;
			MiniUnitHp[i] = 10;

			MiniUnitX[i] = PlanetX[m];
			MiniUnitY[i] = PlanetY[m];

		}
	}

	//要塞座標
	spriteBigUnit->SetPosition({ bigunitX - mapX ,bigunitY - mapY });


}
