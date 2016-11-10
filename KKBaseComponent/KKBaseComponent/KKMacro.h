//
//  KKMacro.h
//  KKKit
//
//  Created by MR.KING on 16/7/8.
//  Copyright © 2016年 KING. All rights reserved.
//

#ifndef KKMacro_h
#define KKMacro_h

/******************自定义宏*****************/
#define KKDeprecated(message) __deprecated_msg("##message##")

#define KK_IPHONE_OS_VERSINO_MAX_ALLOWED __IPHONE_OS_VERSION_MAX_ALLOWED

// 如果是非OBJC_ARC,线程需要管理内存 see: http://stackoverflow.com/questions/8618632/does-arc-support-dispatch-queues
#if OS_OBJECT_USE_OBJC
#undef KKDispatchQueueRelease
#undef KKDispatchQueueSetterProperty
#define KKDispatchQueueRelease(q)
#define KKDispatchQueueSetterProperty strong
#else
#undef SDDispatchQueueRelease
#undef SDDispatchQueueSetterProperty
#define SDDispatchQueueRelease(q) (dispatch_release(q))
#define SDDispatchQueueSetterProperty assign
#endif


#define dispatch_main_sync_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

#define dispatch_main_async_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

#define KScreenSize [UIScreen mainScreen].bounds.size
#define KScreenWidth KScreenSize.width
#define KScreenHeight KScreenSize.height

#define KNavBarHeight (44.0)

#define KStatusBarHeight (20.0)

#define KFullNavBarHeight (64.0)

#define IPHONE_VERSION_4 ([[UIDevice deviceModel] isEqualToString:UIDeviceModel4])

#define IPHONE_VERSION_5 ([[UIDevice deviceModel] isEqualToString:UIDeviceModel5])

#define IPHONE_VERSION_6 ([[UIDevice deviceModel] isEqualToString:UIDeviceModel6])

#define IPHONE_VERSION_PLUS ([[UIDevice deviceModel] isEqualToString:UIDeviceModelPlus])

#define KSingleton(className)\
+(instancetype)shareManager{\
static className * objc ;\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
if (!objc) {\
objc = [[className alloc]init];\
}\
});\
return objc;\
}\


#define KDisPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)


/******************生成颜色*****************/
// 透明颜色
#define ClearColor [UIColor clearColor]
// 黑色
#define BlackColor [UIColor blackColor]
// 白色
#define WhiteColor [UIColor whiteColor]
// 红色
#define RedColor [UIColor redColor]
// 灰色
#define GrayColor [UIColor grayColor]

#define KKWeak(obj) __weak typedof(obj) weak##obj = obj;
#define KKWeakSelf KKWeak(self)


#define HEXCOLOR(c)                         [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:(c&0xFF)/255.0 alpha:1.0]

#define RGBCOLOR(r, g, b)       [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r, g, b, a)   [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]



/******************结构体*****************/
#ifndef KP
#define KP(x,y) CGPointMake(x,y)
#endif

#ifndef KRect
#define KRect(x,y,w,h) CGRectMake(x,y,w,h)
#endif

#endif /* KKMacro_h */
