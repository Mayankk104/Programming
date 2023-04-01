find src/ -type f ! -name "*.*"
find src/ -type f ! -name "*.*" -exec rm {} \;

# find -E src/ -regex '.*\.(o|out|exe)' # works in Macs 
# find -E src/ -regex '.*\.(o|out|exe)' -delete

find src/ -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" \) # works in any linux distro
find src/ -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" \) -delete

find src/ -type d -name "*.dSYM*"
find src/ -type d -name "*.dSYM*" -exec rm -r {} +