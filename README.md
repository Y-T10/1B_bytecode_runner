# 80VM

```
     ___    ___    __      __ __  __ 
    / _ \  / _ \   \ \    / /|  \/  |
   | (_) || | | |   \ \  / / | \  / |
    > _ < | | | |    \ \/ /  | |\/| |
   | (_) || |_| |     \  /   | |  | |
    \___/  \___/       \/    |_|  |_|

```

## はじめに
これはいつぞやの用事で作成した某80のエミュレータです．
現在は1バイトのオペコードのみ対応しています．

## プログラムの実行方法
- 必要なもの
    * g++
    * GNU make
    * その他ビルド及び実行に必要なもの

1. makeコマンドでプログラムを生成する
2. 実行したいバイナリファイルを作成する
3. 作成したバイナリファイルを引数に付けてプログラムを実行する

## ディレクトリの説明
- res: リソースファイルディレクトリ。実行時に必要なファイルが入っている。
- src: ソースファイルディレクトリ。
- README.md      : このファイルです。
- makefile       : GNU Makeが実行するファイルです。
                   シミュレータを生成する際に使用します。
