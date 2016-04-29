##1.3.2题目2：接馅饼  

###完成效果
![](http://i2.piimg.com/24a9f40a398ae472.png)

###【问题描述】  
用 C 语言编写一个简单的“接馅饼”游戏程序，实现所要求的基本功能。在完成基本功能后，可以选择实现数项扩展功能。  

###【基本功能要求】  
从屏幕上方水平随机位置匀速掉下小球，小球可能是馅饼（占大约2/3），也可能是炸弹（占大约1/3），如果是馅饼，每过t1时间，则变为馅饼，但一闪后又恢复为小球，炸弹也类似变化。屏幕下方有一个碗，随键盘操作横向运动，接到一个馅饼则加10分，如果馅饼未接到后落地则减10分（可出现负值）；接到炸弹，碗被炸毁，扣100分，再出现第二只碗，最多有3只碗。3只碗均被炸毁，游戏结束。  
也可中途按下“结束”按钮结束游戏。  
动态显示玩家得分。  
###一、主界面
界面分为3个区域：游戏区、控制区、信息显示区。游戏界面如图所示。鼓励把界面做的更美观。  
![](http://i4.tietuku.com/f69d3dab2a6adc4c.png)

游戏区中有多个圆球连续落下，没有被接住的，到游戏区底端自动消失。  
控制区有“开始”、“结束”、“退出”等按钮，扩展功能所需的按钮和同学自己添加功能的按钮也显示在此区域。  
信息显示区显示游戏的状态信息，例如用户名、游戏所得分数、剩余时间（秒）等。  
###二、具体要求
####1、用户名
程序运行时先输入用户名，再显示游戏界面，并把用户名显示在信息显示区中。  
####2、控制区按钮
单击“开始”按钮，游戏开始，自动计时开始，圆球开始按指定间隔出现，并向下落下。  
单击“结束”按钮，本盘游戏结束，但不结束程序。若再按“开始”按钮，则下一盘游戏从头开始。重新计分。  
单击“退出”按钮，结束整个程序。  
单击“保存成绩”按钮，执行相应功能（见7）。  
单击“显示最高分”按钮，执行相应功能（见扩展功能2）。  
其他扩展功能的按钮（如果有的话）。  
####3、圆球的出现和移动
每次从游戏区的顶端出现一个圆球，按指定时间间隔（例如2秒）连续出现，圆球的横向位置在游戏区内随机产生，匀速下落，掉到碗里或落到地上则消失。每个圆球只能是炸弹或馅饼，但一开始均显示为相同的圆球。下落过程中会瞬间变回原形（馅饼或炸弹），但很快又变回圆球并多次变换。  
####4、玩家操作及计分
单击“开始”则一盘游戏开始，每盘有3只碗可用。  
玩家用键盘控制大碗水平移动，接到圆球后，如果是馅饼则家10分，如果是炸弹，则炸毁大碗，并减100分，再出现新碗， 3只碗都被炸毁，本盘游戏结束。3只碗的累加分数为本盘游戏的分数。  
####5、显示得分
动态显示本盘游戏的得分。按“结束”按钮后，本次得分清零。再按“开始”按钮，则下一盘游戏开始。  
####6、时间显示
每盘游戏有确定的时间限制（例如200秒），在信息显示区动态显示剩余时间，时间到，则自动结束本盘游戏。  
####7、保存成绩
单击“保存成绩”按钮，将当前用户的用户名和本盘积分存入文件。（是否要求输入文件名自己决定。同一个用户每次成绩都保存）  

####【扩展功能要求】
#####1、优化“开始”按钮
单击“开始”按钮后，“开始”按钮变为“暂停”按钮，单击“暂停”按钮则游戏暂停，按钮变为“开始”按钮。再单击“开始”按钮，游戏可以从暂停点继续运行。  
#####2、显示最高分
单击“显示最高分”按钮，在文件中找到当前用户多次成绩中的最高分，显示在信息显示区中。  

#####3、游戏分级
在游戏开始前，可在控制区通过按钮选择游戏级别。  
不同级别圆球的出现频率不同，圆球的下落速度不同，小球显示为原形的时间不同。
#####4、将游戏的当前状态存盘和导入
存盘：按指定文件名，将当前游戏的状态（各圆球状态）、用户名、得分等存入文件，游戏继续。  
导入：删除当前游戏（删除前应提问是否存盘），将文件中存储的游戏状态恢复到屏幕上，导入的游戏继续运行。导入文件中的游戏后，得分恢复到存盘时的得分。
#####5、自己添加的其他功能
自己添加的使游戏更加有趣的功能，或使界面更加美观的功能（例如，鼠标单击控制区中的按钮时，按钮有被按下去的效果，松开时，有弹回来的效果）。  
#####【注意】
游戏区中出现圆球的个数必须是随机的，不能限制其个数。
