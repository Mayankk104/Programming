find src/ -type f ! -name "*.*"
find src/ -type f ! -name "*.*" -exec rm {} \;

find -E src/ -regex '.*\.(o|out|exe)' 
find -E src/ -regex '.*\.(o|out|exe)' -delete

find src/ -type d -name "*.dSYM*"
find src/ -type d -name "*.dSYM*" -exec rm -r {} +