// swift-tools-version:5.6
//  Package.swift
//  GuardianConnect
//
//

import PackageDescription

let package = Package(
	name: "GuardianConnect",
	platforms: [
		.macOS(.v10_15),
		.iOS(.v13)
	],
	products: [
		.library(name: "GuardianConnect", targets: ["GuardianConnect"])
	],
	targets: [
		.binaryTarget(name: "GuardianConnect", 
			      url:"https://github.com/GuardianFirewall/GuardianConnect/releases/download/1.6/GuardianConnect.xcframework.zip", 
			      checksum: "418c1a739ab0a09e9aad28a9f4a49d9dee80a5accbcdf5ad3291a706f97f01d2")
	]
)
