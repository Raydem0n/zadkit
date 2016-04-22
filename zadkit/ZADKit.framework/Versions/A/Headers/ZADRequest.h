//
//  ZADRequest.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Genders to help deliver more relevant ads.
typedef NS_ENUM(NSInteger, ZADGender) {
    kZADGenderUnknown,  ///< Unknown gender.
    kZADGenderMale,     ///< Male gender.
    kZADGenderFemale    ///< Female gender.
};

/// Specifies optional parameters for ad requests.
@interface ZADRequest : NSObject

/// Returns a default request.
+ (instancetype)request;

#pragma mark Collecting SDK Information

/// Returns the version of the SDK.
+ (NSString *)sdkVersion;

#pragma mark Testing

/// Test ads will be returned for devices with device IDs specified in this array.
@property(nonatomic, copy) NSArray *testDevices;

#pragma mark User Information

/// Provide the user's gender to increase ad relevancy.
@property(nonatomic, assign) ZADGender gender;

/// Provide the user's birthday to increase ad relevancy.
@property(nonatomic, copy) NSDate *birthday;

/// The user's current location may be used to deliver more relevant ads. However do not use Core
/// Location just for advertising, make sure it is used for more beneficial reasons as well. It is
/// both a good idea and part of Apple's guidelines.
- (void)setLocationWithLatitude:(CGFloat)latitude
                      longitude:(CGFloat)longitude
                       accuracy:(CGFloat)accuracyInMeters;

#pragma mark Contextual Information

/// Array of keyword strings. Keywords are words or phrases describing the current user activity
/// such as @"Sports Scores" or @"Football". Set this property to nil to clear the keywords.
@property(nonatomic, copy) NSArray *keywords;

/// Color.
@property(nonatomic, copy) UIColor *referenceColor;

/// URL string for a webpage whose content matches the app content. This webpage content is used for
/// targeting purposes.
@property(nonatomic, copy) NSString *contentURL;

@end
