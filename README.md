# Hacker Quest

## Hacker Questについて
このゲームはC言語の学習用のために作りました。<br>
優しめのコードを中心に書いています。

## このゲームの概要
主人公がモンスターを倒していくクエスト形式のゲームです。<br>
クリア条件は、<br>
ラスボスを倒して秘密のパスワードを入手し、宝箱を開けることです。<br>

## このゲームの裏設定
このゲームの裏設定はバイナリファイルをユーザーに体験してもらうことです。<br>
Hacker Questのラスボスはかなり強く設定されています。<br>
なので、このゲームをクリアするためには<br>
バイナリファイルを直接書き換える必要があります。<br>

## 出現する敵の名前
1. デニス・リッチー
C言語の開発者であり、Unixオペレーティングシステムの共同開発者。彼の技術的な貢献は、現代のソフトウェア開発の基盤を築いたといえます。C言語は現在でも多くのシステムやアプリケーションに使用され、UnixはLinuxなどの多くのオペレーティングシステムの祖先となっています。
名言：
```
「The only way to learn a new programming language is by writing programs in it.」
「新しいプログラミング言語を学ぶ唯一の方法は、それでプログラムを書くことだ。」
```
2. エリック・S・レイモンド 
How To Become A Hackerの著者。
オープンソース運動を通じて、プログラミングやハッカー文化に深く影響を与えた人物。
```
「Good programmers know what to write. Great ones know what to rewrite and reuse.」
「良いプログラマーは何を書くべきかを知っている。偉大なプログラマーは、何を書き直し、再利用するべきかを知っている。」
```
3. ポールグレアム
Lisper。ハッカーと画家の著者。YahooStoreの開発者。IPhoneの出現を予測していた者。DropBox、Airbnb、Stripeなど名だたる企業への投資家。
必殺技は、1日16時間働け！
```
「It's hard to do a really good job on anything you don't think about in the shower.」
「シャワーを浴びているときに考えないことでは、本当に良い仕事はできない。」
```

## このゲームの流れ

1. タイトルとサブタイトルを表示します。
```
**Hacker Quest**
Hacker Quest is highly difficult,
and your best chance of completing it is by improving your hacking skills.
```
日本語訳：<br>
```
ハッカークエストの難易度は非常に高く設定されています。
あなたがこのクエストをクリアする最善の方法はハッキングの技術を磨くことです
```
このゲームを始めますか？
(0:no or 1:yes or 7:宝箱を開ける)

入力シーン

```
主人公の名前を4文字以内で入力してください。
...
主人公の職業を選択してください。
(1.勇者 or 2.魔法使い or 3.盗賊 or 4.ニート 5.エンジニア)
...
たかのり(勇者)
...
クエストに挑戦する準備はできましたか？
(0:no or 1:yes)
...
```

クエスト開始
```
たかのり（勇者）
HP：200、攻撃力：120
```
以下はバトルシーン
```
...
...
...
**STAGE 1/3**
...
...
野生のリッチーが現れた...!!!
C言語の開発者であり、Unixオペレーティングシステムの共同開発者。
HP：10、攻撃力:10
...
あなたは(専攻 or 後攻)になりました...!!!
...
攻撃を選択してください。
...
(1:攻撃 or 2:必殺)
...
たかのりは攻撃をした...!!!
...
リッチーは40ダメージを受けた..!!!
...
リッチーは言葉を残して消え去った...!!!
...
「The only way to learn a new programming language is by writing programs in it.」
(「新しいプログラミング言語を学ぶ唯一の方法は、それでプログラムを書くことだ。」)
...
...
**STAGE 2/3**
...
...
野生のレイモンドが現れた...!!!
How To Become A Hackerの著者。
オープンソース運動を通じて、プログラミングやハッカー文化に深く影響を与えた人物。
...
...
あなたは(専攻 or 後攻)になりました...!!!
...
攻撃を選択してください
...
レイモンドは40ダメージを受けた...!!!
...
レイモンドは言葉を残して消え去った...!!!
...
「Good programmers know what to write. Great ones know what to rewrite (and reuse).」
(「良いプログラマーは何を書くべきかを知っている。偉大なプログラマーは、何を書き直し、再利用するべきかを知っている。」)
...
...
...
**STAGE 3/3(Final Stage)**
...
...

野生のグレアムが現れた...!!!
最強のLisper。ハッカーと画家の著者。YahooStoreの開発者。IPhoneの出現を予測していた者。DropBox、Airbnb、Stripeなど名だたる企業への投資家。
...
...
あなたは(専攻 or 後攻)になりました...!!!
...
攻撃を選択してください
...
グレアムは40ダメージを受けた...!!!
...
グレアムのHPは160になった...
...
グレアムの必殺(1日16時間働け..!!!)
...
あなたは200ダメージを受けた...!!!
...
あなたは息絶えた...
...
...
...
...
**GAME OVER**
...
...
...


```




