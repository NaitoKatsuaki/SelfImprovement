# 🧭 自己研鑽マスタープラン
## テーマ：C++設計 × 通信理解 × アプリ統合 × AI駆動開発
期間：3か月想定（週6時間 × 12週）※延長ペースでOK
開発環境：Windows / Visual Studio（C++） / VSCode（Python, React）

---

## 🧩 フェーズ1：C++設計とリアルタイム処理基礎（第1〜4週）

| ✅ | 週 | 学習テーマ | タスク内容 | 成果物 / 目標 |
|----|----|-------------|-------------|----------------|
| ✅ | 1 | 所有権とメモリ管理 | - [Effective Modern C++項目13〜18](https://www.amazon.co.jp/dp/4894714999)<br>- `unique_ptr` / `shared_ptr` / `weak_ptr`の動作を確認<br>- copy/moveコンストラクタを自作 | 画像バッファを保持する`FrameBuffer`クラス |
| ✅ | 1 | moveセマンティクス演習 | - `std::move`と右辺値参照の動作理解<br>- コピー禁止＋ムーブ専用クラスを設計 | コピー禁止・ムーブ専用クラスを作成 |
| ✅ | 1 | RAIIと例外安全 | - [CppCon: Herb Sutter “Leak Freedom by Default”](https://www.youtube.com/watch?v=JfmTagWcqoE)<br>- `noexcept`指定とtry/catchで例外安全を検証 | 安全なデストラクタ設計を実装 |
| ☐ | 2 | スレッド基礎 | - [cppreference: std::thread](https://en.cppreference.com/w/cpp/thread/thread)<br>- `join` / `detach`の違いを理解 | 並列出力サンプルプログラム |
| ☐ | 2 | 排他制御 | - [cppreference: std::mutex](https://en.cppreference.com/w/cpp/thread/mutex)<br>- デッドロック発生条件を確認 | スレッドセーフなカウンター |
| ☐ | 2 | 条件変数 | - [cppreference: condition_variable](https://en.cppreference.com/w/cpp/thread/condition_variable)<br>- producer-consumer構造で画像処理模擬 | 3スレッド構成のパイプラインデモ |
| ☐ | 3 | タスク制御 | - `std::chrono`で周期制御（60fpsループ）<br>- 実行時間計測を追加 | 簡易リアルタイム処理ループ |
| ☐ | 4 | モジュール設計演習 | - Model / Controller / IO分割を意識してクラス設計<br>- `constexpr`, `enum class`, `noexcept`を活用 | 拡張可能なアプリ骨格を実装 |

---

## 🌐 フェーズ2：WinSock2で学ぶ通信基礎（第5〜8週）

| ✅ | 週 | 学習テーマ | タスク内容 | 成果物 / 目標 |
|----|----|-------------|-------------|----------------|
| ☐ | 5 | TCP/IP理論 | - [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/)<br>- OSI参照モデルとTCP/IP階層整理<br>- ソケット通信の流れを図解 | 自作通信フロー図（アプリ〜物理層） |
| ☐ | 6 | WinSock2入門 | - [Microsoft Docs: Complete Server Code](https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code)<br>- `socket` / `bind` / `listen` / `accept` の流れを実装 | TCPサーバ・クライアント（echoアプリ） |
| ☐ | 6 | TCPハンドシェイク理解 | - [Wireshark入門ガイド](https://www.wireshark.org/docs/wsug_html_chunked/)<br>- 3-way handshakeを可視化 | 通信接続時のパケットシーケンスを説明できる |
| ☐ | 7 | バイナリデータ通信 | - `std::vector<uint8_t>`で画像送受信<br>- 部分送信問題とパケット再構成を体験 | 画像送信・受信プログラム |
| ☐ | 7 | TCPバッファと遅延制御 | - Nagleアルゴリズム／送信バッファ挙動を調査<br>- [TCP/IP Illustrated, Vol.1](https://www.amazon.co.jp/dp/0201633469)該当章を読む | バッファ挙動を図で説明できる |
| ☐ | 8 | マルチクライアント通信 | - `select()`で複数接続を処理<br>- クライアントごとにスレッドを生成 | 複数クライアント対応チャットサーバ |
| ☐ | 8 | 通信設計まとめ | - スレッド安全な送受信クラスを設計<br>- 接続管理・切断検知を追加 | 通信モジュール試作版完成 |

---

## ⚙️ フェーズ3：通信 × Web統合（第9〜12週）

| ✅ | 週 | 学習テーマ | タスク内容 | 成果物 / 目標 |
|----|----|-------------|-------------|----------------|
| ☐ | 9 | Flask入門 | - [Flask公式チュートリアル](https://flask.palletsprojects.com/en/stable/tutorial/)<br>- `/process` `/status` APIを作成 | JSONレスポンスを返すFlaskサーバ |
| ☐ | 9 | HTTP構造理解 | - HTTPリクエスト構造を図解<br>- [MDN: HTTP Overview](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview)を読む | C++からFlaskへPOST送信成功 |
| ☐ | 10 | WebSocket通信 | - [Flask-SocketIO公式Doc](https://flask-socketio.readthedocs.io/en/latest/)<br>- 常時接続通信を実装 | Flaskサーバでリアルタイム進捗更新 |
| ☐ | 10 | C++⇄Flask統合 | - C++でTCP通信→Flaskへ結果POST<br>- Python側で受け取って可視化 | 結果データ転送デモ完成 |
| ☐ | 11 | JSONデータ構造設計 | - [nlohmann/json GitHub](https://github.com/nlohmann/json)<br>- 通信結果をJSONで統一 | JSON入出力統合 |
| ☐ | 11 | 3D可視化入門 | - [Three.js Fundamentals](https://threejs.org/docs/)<br>- Flask＋Three.jsで点群描画 | 3D表示デモ（静的） |
| ☐ | 12 | アプリ統合 | - C++処理＋通信＋Flask UI連携を整理<br>- AIに設計レビュー依頼 | 「3D通信統合アプリ」初版完成 |
| ☐ | 12 | 最適化とドキュメント化 | - [Visual Studio Profilerガイド](https://learn.microsoft.com/en-us/visualstudio/profiling/?view=vs-2022)<br>- プロファイル・通信ロス対策 | ドキュメント整備（Markdown設計書） |

---

## 🧱 フェーズ4：拡張・統合（第13〜15週以降）

| ✅ | 週 | 学習テーマ | タスク内容 | 成果物 / 目標 |
|----|----|-------------|-------------|----------------|
| ☐ | 13 | React導入（AI主導） | - [React公式チュートリアル](https://react.dev/learn)<br>- FlaskバックエンドをAPI接続 | React Dashboard構築 |
| ☐ | 14 | 座標変換とロボット統合 | - [Eigen公式Doc](https://eigen.tuxfamily.org/)<br>- カメラ→ロボット座標変換を再現 | 姿勢可視化・myCobot連携準備 |
| ☐ | 15 | 設計思想まとめ | - 設計方針・責務分離・通信構造を文章化<br>- GitHub公開を想定してREADME作成 | 技術ポートフォリオ完成 |
