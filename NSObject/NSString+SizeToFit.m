//
//  NSString+SizeToFit.m
//  UniversalApp
//
//  Created by 沈丰元 on 2017/12/15.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "NSString+SizeToFit.h"

@implementation NSString (SizeToFit)
- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)maxSize {

  //返回字符串所占用的尺寸.
  NSDictionary *attrs = @{NSFontAttributeName : font};
  return [self boundingRectWithSize:maxSize options:NSStringDrawingUsesLineFragmentOrigin attributes:attrs context:nil].size;

}
@end
