//
//  UIButton+EXBadge.h
//  EXCountDownButton
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 sfy921011@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (EXBadge)
/***  角标所在的Label,用于自定义*/
@property (strong, nonatomic) UILabel *badge;
/***  角标数值*/
@property (nonatomic) NSString *badgeValue;
/***  角标背景颜色 默认：红色*/
@property (nonatomic) UIColor *badgeBGColor;
/***  角标数字颜色  默认：白色*/
@property (nonatomic) UIColor *badgeTextColor;
/***  角标字体大小 默认：12*/
@property (nonatomic) UIFont *badgeFont;
/***  角标内边距  默认：8*/
@property (nonatomic) CGFloat badgePadding;
/***  角标最新尺寸 默认：6*/
@property (nonatomic) CGFloat badgeMinSize;
/***  角标X轴偏移量 */
@property (nonatomic) CGFloat badgeOriginX;
/***  角标Y轴偏移量 默认：-4*/
@property (nonatomic) CGFloat badgeOriginY;
/***  角标数字为0时，是否隐藏角标 默认：Yes*/
@property BOOL shouldHideBadgeAtZero;
/***  角标数字变化时，是否需要动画效果 默认：Yes*/
@property BOOL shouldAnimateBadge;
@end
