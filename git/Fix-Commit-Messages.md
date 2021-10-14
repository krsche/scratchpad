# Fix Commit Messages

## Important commands
```bash
# Show history (if git tree alias doesnt exist, run `git log`)
git tree

# Show specific commit (2 after current HEAD)
git log -n 1 HEAD~2 

# Rebase interactively, specify first commit BEFORE the commit you want to edit (HEAD~3 in this case)
git rebase -i HEAD~3

# When editor opens, replace `pick` with `reword` to just update the message on that commit
# then save and close editor
# new editor opens --> update message --> save and close editor
# done, review changes by rerunning `git tree` / or `git log`
```

## Demo
![git-fix-commit-message-demo](.attachments/git-fix-commit-message-demo.png)

