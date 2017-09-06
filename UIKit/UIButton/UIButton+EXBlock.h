//
//  UIButton+EXBlock.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 沈丰元. All rights reserved.
//  按键点击Block回调

#import <UIKit/UIKit.h>

typedef void (^EXTouchedButtonBlock)(NSInteger tag);

@interface UIButton (EXBlock)

-(void)addActionHandler:(EXTouchedButtonBlock)touchHandler;

@end
