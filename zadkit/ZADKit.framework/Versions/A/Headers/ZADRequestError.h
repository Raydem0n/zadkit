//
//  ZADRequestError.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>

/// NSError codes for ZAD error domain.
typedef NS_ENUM(NSInteger, ZADErrorCode) {
    /// The ad request is invalid. The localizedFailureReason error description will have more
    /// details. Typically this is because the ad did not have the ad unit ID or root view
    /// controller set.
    kZADErrorInvalidRequest,
    
    /// The ad request was successful, but no ad was returned.
    kZADErrorNoFill,
    
    /// There was an error loading data from the network.
    kZADErrorNetworkError,
    
    /// The ad server experienced a failure processing the request.
    kZADErrorServerError,
    
    /// The current device's OS is below the minimum required version.
    kZADErrorOSVersionTooLow,
    
    /// The request was unable to be loaded before being timed out.
    kZADErrorTimeout,
    
    /// Will not send request because the interstitial object has already been used.
    kZADErrorInterstitialAlreadyUsed,
    
    /// The mediation response was invalid.
    kZADErrorMediationDataError,
    
    /// Error finding or creating a mediation ad network adapter.
    kZADErrorMediationAdapterError,
    
    /// The mediation request was successful, but no ad was returned from any ad networks.
    kZADErrorMediationNoFill,
    
    /// Attempting to pass an invalid ad size to an adapter.
    kZADErrorMediationInvalidAdSize,
    
    /// Internal error.
    kZADErrorInternalError,
    
    /// Invalid argument error.
    kZADErrorInvalidArgument,
    
    /// Received invalid response.
    kZADErrorReceivedInvalidResponse
};

/// Represents the error generated due to invalid request parameters.
@interface ZADRequestError : NSError

@end
