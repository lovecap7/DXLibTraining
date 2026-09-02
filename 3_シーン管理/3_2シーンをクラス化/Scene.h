#pragma once

// 抽象クラスにabsrtactキーワードを加えるとより意図が明確になる
// 必須ではない
// またクラス内に純粋仮想関数が無くても抽象クラスになるという特性がある
// (が、結局抽象クラスを作る=純粋仮想関数作る　なので大した意味はない)
class Scene abstract
{
public:

	// ★純粋仮想関数には = 0 の代わりにabstractを使うことができる
	// 後者の方が新しい構文で、警告とかがより詳しく出るので安心

	// 初期化処理
	virtual void Init() abstract;

	// 更新処理

	// 今回は更新時に遷移するシーンをreturnさせる設計にする
	virtual Scene* Update() abstract;

	// 描画
	virtual void Draw() abstract;

	// 終了処理
	virtual void End() abstract;

private:

	// ここにはできるだけ何もない方がいい
	// 今回は全てのシーンに画像を描画するハンドルを持たせているが、
	// だからと言って基底クラスで変数を用意していいわけじゃない
	// 使わないシーンも作れるからである
};

