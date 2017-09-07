//
//  UITextField+EXCategory.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/7.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void(^EditEndBlock)(NSString *text);
@interface UITextField (EXCategory)
/** 占位文字颜色*/
@property (nonatomic, strong) UIColor * placeholderColor;
/**
 *  限制输入长度
 *
 *  @param length 长度
 *  @param block  回调
 */
- (void)limitTextLength:(NSInteger)length block:(EditEndBlock)block;
/**
 *  uitextField 抖动效果
 */
- (void)shake;
@end
