set(ProjectName "NFChatPlugin")
file(GLOB NFChatPlugin_ROOT_Cpp
	*.cpp)
	
file(GLOB NFChatPlugin_ROOT_Hpp 
	*.h)

add_library(NFChatPlugin STATIC
	${NFChatPlugin_ROOT_Cpp}
	${NFChatPlugin_ROOT_Hpp})
	
set_target_properties( NFChatPlugin PROPERTIES OUTPUT_NAME_DEBUG "NFChatPlugin_d")
set_target_properties( NFChatPlugin PROPERTIES PREFIX "")
set_target_properties( NFChatPlugin PROPERTIES 
	FOLDER "NFMidWare/NFChatPlugin"
	ARCHIVE_OUTPUT_DIRECTORY ${NFOutPutDir}
	RUNTIME_OUTPUT_DIRECTORY ${NFOutPutDir}
	LIBRARY_OUTPUT_DIRECTORY ${NFOutPutDir} )
link_NFSDK("NFChatPlugin")

if(UNIX)

	target_link_libraries(NFChatPlugin -static-libstdc++)

	add_definitions(
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)
	
else()

	target_link_libraries(NFChatPlugin -static-libstdc++)

	add_definitions(
		-DWIN
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)
endif()
