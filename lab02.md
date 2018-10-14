
# 用Construct 2搭建游戏基本框架
## 1.为游戏添加背景
![avatar](https://www.scirra.com/images/articles/bg.png) 
### 首先，在Construct 2的空白背景上双击，出现如下页面。
![avatar](<img src='http://i4.bvimg.com/665123/26425be06d9322be.png'>)
### 点击tile background，出现如下对话框,点击红圈处，在弹出对话框内选择上文的背景图。
![avatar](<img src='http://i4.bvimg.com/665123/5230090dba077140.png'>)
### 接着看界面左边的Properties Bar，在下方的设置中将该图片的position设为（0,0），将size设为（1280,1024）。这样能使背景图完全贴合布局。
![avatar](<img src='http://i4.bvimg.com/665123/3ab6bbb3383e94c7.png'>)

## 2.添加新图层
   为了不在操作后面物件时候误触背景图，我们选择新加一个图层，并锁定背景图层。
![avatar](<img src='http://i4.bvimg.com/665123/874732603189c472.png'>)
在右上角的project栏中有图层相关选项，点击“+”号添加新图层，并可以按“笔”图标为各个图层命名。点击前方的锁来解锁或锁定图层。

## 3.为游戏添加物件：通过一次一个地拖动图片来将物件添加。（如果一次性添加的话，这些物件会放到一个sprite中）
### 玩家：![avatar](https://www.scirra.com/images/articles/player.png)
### 怪物：![avatar](https://www.scirra.com/images/articles/monster.png)
### 子弹：![avatar](https://www.scirra.com/images/articles/Bullet.png)
### 爆炸效果：![avatar](https://www.scirra.com/images/articles/explode.png)

## 4.添加行为
### 先给玩家添加行为：选中玩家，在左侧的properties bar中，点击“add behavior"。
![avatar](<img src='http://i1.bvimg.com/665123/8e3631a76526bd95.png'>)
### 在弹出来的对话框中按左上角的“+”号，选择下方的“eight direction(八向运动)”
![avatar](<img src='http://i4.bvimg.com/665123/4baf35e2dd0aa4cc.png'>)
### 同理，再加入“scroll to"（滚动）和“bound to layout”（限制在布局中）。
### 再如法炮制，给子弹添加Bullet movement （向前运动）与 Destroy outside layout（离开布局后消失）动作，给爆炸添加Fade（渐隐）动作，给怪物添加Bullet movement动作。
### 在界面左上方的菜单栏中，点击run的图标，一个小三角。
![avatar](<img src='http://i1.bvimg.com/665123/2c977235c25075c5.png'>)
     
     这样，我们就可以在浏览器上概览我们游戏的大体了！
![avatar](<img src='http://i2.bvimg.com/665123/53e8bf1d81552a3b.gif'>)

