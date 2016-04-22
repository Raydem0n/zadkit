Pod::Spec.new do |s|
  s.name = 'ZADKit'
  s.version = '0.1.0'
  s.summary = 'A Ad library.'
  s.license = 'MIT'
  s.authors = {"Raydem0n"=>"conanhawke@hotmail.com"}
  s.homepage = 'https://github.com/Raydem0n/ZADKit'
  s.description = <<-DESC
                    It's a iOS Ad library.
                    DESC
  s.source = { :git => "https://github.com/Raydem0n/ZADKit.git", :tag => s.version.to_s }

  s.platform = :ios, '6.0'
  s.ios.platform             = :ios, '6.0'
  s.ios.preserve_paths       = 'zadkit/ZADKit.framework'
  s.ios.public_header_files  = 'zadkit/ZADKit.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'zadkit/ZADKit.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'zadkit/ZADKit.framework'
end
