# Workflow Directory

This directory contains the workflows for building and testing your project using GitHub Actions.

## Workflows

- [Build](./build.yml): This workflow is triggered on pushes to the `main` branch and pull requests targeting the `main` branch. It sets up the C compiler, checks out the repository, and builds your project using the `make` command. It also runs the tests using the `make test` command.

- [Checkout](./checkout.yml): This workflow is triggered on pushes to the `main` branch and pull requests targeting the `main` branch. It checks out the contents of the repository into the workflow's workspace using the `actions/checkout` action.

- [Setup](./setup.yml): This workflow is triggered on pushes to the `main` branch and pull requests targeting the `main` branch. It sets up the necessary environment for building and testing your project. The setup process may include installing dependencies, configuring tools, or setting up compilers.

- [Test](./test.yml): This workflow is triggered on pushes to the `main` branch and pull requests targeting the `main` branch. It sets up the C compiler, checks out the repository, and builds your project using the `make` command. It then executes the tests using the `make test` command.

## Getting Started

To use these workflows in your project, follow these steps:

1. Copy the `.github/workflows` directory from this repository to your project repository.

2. Customize the workflows (`build.yml`, `checkout.yml`, `setup.yml`, and `test.yml`) as needed for your project. You may need to adjust the build commands, test commands, or add additional steps for dependencies specific to your project.

3. Commit and push the workflows to your repository.

4. GitHub Actions will automatically pick up the workflows and execute them when the specified events occur.
