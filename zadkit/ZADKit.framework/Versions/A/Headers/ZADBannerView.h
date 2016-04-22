//
//  ZADBannerView.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZADRequest.h"
#import "ZADBannerViewDelegate.h"

@interface ZADBannerView : UIView

#pragma mark Initialization

/// Initializes and returns a banner view with the specified ad size and origin relative to the
/// banner's superview.
//- (instancetype)initWithAdSize:(ZADAdSize)adSize origin:(CGPoint)origin;

/// Initializes and returns a banner view with the specified ad size placed at its superview's
/// origin.
//- (instancetype)initWithAdSize:(ZADAdSize)adSize;

#pragma mark Pre-Request

/// Required value created on the AdMob website. Create a new ad unit for every unique placement of
/// an ad in your application. Set this to the ID assigned for this placement. Ad units are
/// important for targeting and statistics.
///
/// Example AdMob ad unit ID: @"ca-app-pub-0123456789012345/0123456789"
@property(nonatomic, copy) IBInspectable NSString *adUnitID;

/// Required reference to the current root view controller. For example the root view controller in
/// tab-based application would be the UITabViewController.
@property(nonatomic, weak) IBOutlet UIViewController *rootViewController;

/// Required to set this banner view to a proper size. Never create your own ZADAdSize directly. Use
/// one of the predefined standard ad sizes (such as kZADAdSizeBanner), or create one using the
/// ZADAdSizeFromCGSize method. If not using mediation, then changing the adSize after an ad has
/// been shown will cause a new request (for an ad of the new size) to be sent. If using mediation,
/// then a new request may not be sent.
//@property(nonatomic, assign) ZADAdSize adSize;

/// Optional delegate object that receives state change notifications from this ZADBannerView.
/// Typically this is a UIViewController.
@property(nonatomic, weak) IBOutlet id<ZADBannerViewDelegate> delegate;

#pragma mark Making an Ad Request

/// Makes an ad request. The request object supplies targeting information.
- (void)loadRequest:(ZADRequest *)request;

/// A Boolean value that determines whether autoloading of ads in the receiver is enabled. If
/// enabled, you do not need to call the loadRequest: method to load ads.
@property(nonatomic, assign, getter=isAutoloadEnabled) IBInspectable BOOL autoloadEnabled;

@end
