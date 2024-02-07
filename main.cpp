#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1D_03_イトウシュンヤ";

bool Enemy::IsAlive = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemy = new Enemy(640, 360);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		enemy->Move();
		player->Move(keys,preKeys);
		if (!player->GetBullet()->GetIsShot()) {
		     player->GetBullet()->SetPos((int)player->GetPos().x, (int)player->GetPos().y);
		}
		player->GetBullet()->Move();
		player->GetBullet()->IsHit(enemy);

		//IsHitを呼ぶ
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
 		player->GetBullet()->Draw();
		player->Draw();
		enemy->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player,enemy;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
