# xiaofei
tankworld introduction:<br/>
this project is a game based on cocos2dx,let me show you how to use it<br/>
first fo all, you should build a enviroment of cocos2dx,you can download here: http://www.cocos2d-x.org/download
secondly,create a new cocos2dx project ,and then copy the folder which named Classes to override the defualt Classes folder.<br/>
thirdly,when you finish what I mentioned above,you can start this project,however, errors will occur when it runs.just take it easy,because you don't have the pictures and musics in the folder which named Resources. then you should look into the code to find the file path I designed.<br/>

中文介绍：<br/>
这个工程是采用的cocos2dx引擎，要安装这个工程且看下面我的介绍：<br/>
首先呢，使用前，你需要配置cocos2dx环境，你可以去这里下载cocos2dx，忘了说了，我现在工程采用的是cocos2dx 3.4版本。<br/>
然后，新建一个新的cocos2dx的项目，你需要复制我这里的Classes文件夹覆盖新项目生成后的默认的那个Classes文件夹。<br/>
接着呢，当你完成上述操作之后其实这个项目就是可以编译通过的呢，只是当你运行的时候就会发生错误，这个时候不要慌张，其实这只是因为你没有我的Resources文件夹导致的，这个时候你需要看代码中找我怎么通过路径调用文件的。<br/>

文件介绍：<br/>
游戏开始之前，有两个场景，<br/>
一：展示程序LOGO的场景，顺便在后台加载声音素材和游戏纹理----------->preloadScene.h<br/>
二：主菜单，用于用户选择开始游戏，游戏关卡，或者选择联系我们------->MainMenu.h<br/>
    关卡选择菜单--------------------------------------------------->selectView.h<br/>
游戏中涉及到的：<br/>
坦克的实现--------------------------------------------------------->tank.h<br/>
子弹的实现--------------------------------------------------------->bullet.h<br/>
游戏场景基类，抽出每个关卡都存在的公共部分------------------------->BaseScene.h<br/>
游戏中AI机器坦克的管理--------------------------------------------->AISystem.h<br/>
三：
游戏数据处理会用到的库--------------------------------------------->GameHandleLib.h<br/>
游戏屏幕适配简单处理类--------------------------------------------->VisibleRect.h<br/>
游戏数据基础宏定义------------------------------------------------->baseDefine.h<br/>

关卡：<br/>
前面介绍了有一个BaseScene作为关卡场景的基类，基类中先实现场景通用的方法，在特定关卡中的初始化中添加额外的初始化代码，添加特有的方法，用这种方式实现扩展。<br/>
关卡之间是如何关联起来的：  当前只有一个关卡，关联起来使用的是一个关卡控制器：<br/>
<code>
typedef struct controller
{
	const char*					chapterName;		//章节名称
	const char*					chapterLookPath;	//章节预览图地址
	function<BaseLayer*()>		callBack;			//章节调用器
}ChapterController;
static ChapterController chapters[] =
{
	{ "protect princess-apartment of CUG", "pic/chapterTest.png", [](){return Chapter1::create(); } }
};
</code>
当你做好一个关卡后，按照这种方式添加到这个数组中即可。<br/>
<hr/>
<hr/>
if you have a better idea,please don't forget to tell me,and if you can continue my job to finish this game I would be very appreciated^_^<br/>
