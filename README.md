# CBGdImage
这是一个CBrother的libgdimage扩展库

# 源码编译后安装
1. 编译后的CBGdImage动态库放到CBrother目录下

    win_x86 : ext\CBGdImage\win\x86\CBGdImage.dll    
    win_x64 : ext\CBGdImage\win\amd64\CBGdImage.dll    
    linux_x86 : ext\CBGdImage\linux\amd64\CBGdImage.so    
    linux_x64 : ext\CBGdImage\linux\x86\CBGdImage.so    
    macos_x64 : ext\CBGdImage\mac\amd64\CBGdImage.dylib
3. lib/gd.cb和sample/gdtest.cb放到CBrother对应目录下

## 安装成功后使用的例子
```javascript
import lib/gd

function main(parm)
{
	var image = new gd::Image();
	image.createTrueColor(300,300);
	
	var white = image.colorAllocate(255, 255, 255);
	var black = image.colorAllocate(0, 0, 0);
	var blue = image.colorAllocate(0, 0, 255);
	var yellow = image.colorAllocate(255, 255, 0);
	var red = image.colorAllocate(255, 0, 0, 64);
	
	image.fill(0,0,yellow);
	
	image.line(10, 10, 150, 150, black);
	
	image.string(gd::LARGE_FONT,60,60,"Hello world!", blue);
	image.stringUp(gd::MEDIUMBOLD_FONT,60,60,"Hello world!", blue);
	
	image.stringTTF(24,6,100,100,blue,"C:/Windows/Fonts/simhei.ttf","你好啊");
	
	image.saveJpegFile(GetRoot() + "111.jpeg");
	image.savePngFile(GetRoot() + "111.png");
	image.saveGifFile(GetRoot() + "111.gif");
	image.saveBmpFile(GetRoot() + "111.bmp");
	image.saveWebpFile(GetRoot() + "111.webp");
	
	var bytearray = image.saveJpegBytes();
	var file = new File(GetRoot() + "222.jpeg","wb+");
	file.writeBytes(bytearray);
	file.close();
}
```
