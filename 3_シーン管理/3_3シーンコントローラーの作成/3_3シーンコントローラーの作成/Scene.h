#pragma once

class SceneController;

// 抽象クラスにabsrtactキーワードを加えるとより意図が明確になる
// 必須ではない
// またクラス内に純粋仮想関数が無くても抽象クラスになるという特性がある
// (が、結局抽象クラスを作る=純粋仮想関数作る　なので大した意味はない)
class Scene abstract
{
public:

	// ★純粋仮想関数には = 0 の代わりにabstractを使うことができる
	// 後者の方が新しい構文で、警告とかがより詳しく出るので安心

	// SceneControllerの参照を貰う関数
	void RecieveSceneController(SceneController* cont);

	// 初期化処理
	// 3_2から引数を追加
	// SceneControllerのポインタを受け渡すようにする
	virtual void Init() abstract;

	// 更新処理
	// 3_2から仕様を変更
	// Update内でSceneControllerに指示を出してシーン切り替えを行う
	virtual void Update() abstract;

	// 描画
	virtual void Draw() abstract;

	// 終了処理
	virtual void End() abstract;

protected:

	// 派生クラスで使いたいメンバ変数はprotectedにする
	SceneController* controller;

private:

	// ここにはできるだけ何もない方がいい
	// 今回は全てのシーンに画像を描画するハンドルを持たせているが、
	// だからと言って基底クラスで変数を用意していいわけじゃない
	// 使わないシーンも作れるからである
};

