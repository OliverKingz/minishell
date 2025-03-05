# Team Rules for Collaborative Work on GitHub

This document outlines the rules, habits, and best practices for working collaboratively on a GitHub project using the branches `main`, `oliver`, and `raul`.

---

## General Rules

1. **Respect the `main` Branch**:
   - The `main` branch should only contain stable, production-ready code.
   - Never commit directly to `main`. Always use Pull Requests (PRs) to integrate changes.

2. **Work on Personal Branches**:
   - Each developer should work on their own branch (`oliver` or `raul`).
   - No need to create a new branch for every feature; work directly on your personal branch.

3. **Frequent Synchronization**:
   - Keep your personal branch updated with `main` to avoid conflicts.
   - Regularly run `git pull origin main` in your personal branch.

4. **Pull Requests (PRs)**:
   - Create a PR to integrate changes from your personal branch into `main`.
   - Review and approve PRs from other developers before merging.

---

## Habits Before Starting Work

1. **Update Your Branch**:
   - Before starting work, ensure your personal branch is up-to-date with `main`.
   ```bash
   git checkout main
   git pull origin main
   git checkout oliver (or raul)
   git merge main
   ```

2. **Review Issues and PRs**:
   - Check if there are new issues assigned to you or PRs that need review.

---

## Habits After a Day of Work

1. **Commit Your Changes**:
   - Make sure to commit your changes before ending your workday.
   ```bash
   git add .
   git commit -m "Clear and concise description of changes"
   ```

2. **Push Changes to the Remote Repository**:
   - Push your changes to the remote repository to avoid losing work.
   ```bash
   git push origin oliver (or raul)
   ```

3. **Create a Pull Request if Necessary**:
   - If you’ve completed a feature or fix, create a PR to integrate your changes into `main`.

4. **Review and Resolve Conflicts**:
   - If there are conflicts in your PR, resolve them as soon as possible.

---

## Handling Conflicts

1. **Identify Conflicts**:
   - If conflicts arise during a merge or rebase, Git will notify you.

2. **Resolve Conflicts**:
   - Open the conflicting files and resolve them manually.
   - Mark resolved conflicts with `git add <file>`.

3. **Complete the Merge or Rebase**:
   - After resolving conflicts, complete the merge or rebase.
   ```bash
   git merge --continue
   # or
   git rebase --continue
   ```

---

## Code Review

1. **Review PRs from Other Developers**:
   - Review PRs from your teammates and provide constructive feedback.

2. **Approve PRs**:
   - If the code meets standards and has no issues, approve the PR.

3. **Merge the PR**:
   - Once approved, merge the PR into `main`.

---

## Git Commands Cheat Sheet

### 1. **Update Your Personal Branch with `main`**
```bash
git checkout main
git pull origin main
git checkout oliver (or raul)
git merge main
```

- **`git checkout main`**: Switch to the `main` branch.
- **`git pull origin main`**: Download the latest changes from the remote `main` branch and merge them into your local branch.
- **`git checkout oliver`**: Switch to your personal branch (`oliver` or `raul`).
- **`git merge main`**: Merge changes from `main` into your personal branch.

### 2. **Commit Changes**
```bash
git add .
git commit -m "Clear and concise description of changes"
```

- **`git add .`**: Stage all changes in the working directory.
- **`git commit -m "Message"`**: Save changes to the local repository with a descriptive message.

### 3. **Push Changes to the Remote Repository**
```bash
git push origin oliver (or raul)
```

- **`git push origin oliver`**: Push changes from your local branch (`oliver` or `raul`) to the remote repository.

### 4. **Resolve Conflicts**
```bash
git merge --continue
# or
git rebase --continue
```

- **`git merge --continue`**: Continue a merge after resolving conflicts manually.
- **`git rebase --continue`**: Continue a rebase after resolving conflicts manually.

### 5. **Merge a PR into `main`**
```bash
git checkout main
git merge oliver (or raul)
git push origin main
```

- **`git merge oliver`**: Merge changes from the `oliver` branch into `main`.
- **`git push origin main`**: Push the merged changes from `main` to the remote repository.

---

## Summary of Key Git Commands and Flags

| Command                  | Description                                                                 | Important Flags          |
|--------------------------|-----------------------------------------------------------------------------|--------------------------|
| `git checkout`           | Switch between branches or restore files.                                   | `-b` (create new branch).|
| `git pull`               | Download and merge changes from the remote repository.                      | `origin <branch>`.       |
| `git merge`              | Merge changes from one branch into another.                                 | `--continue`.            |
| `git add`                | Stage changes for commit.                                                   | `.` (all files).         |
| `git commit`             | Save changes to the local repository.                                       | `-m` (commit message).   |
| `git push`               | Push changes to the remote repository.                                      | `origin <branch>`.       |
| `git rebase`             | Reapply commits on top of another branch.                                   | `--continue`.            |

---