# List deleted files
deleted_files=$(git ls-files -d)

# Restore each deleted file individually
for file in $deleted_files; do
  git checkout HEAD -- "$file" || echo "Failed to restore $file"
done

# Verify restoration
git status

# Commit the changes
git add .
git commit -m "Restored deleted files"