pipeline {
  agent any
  stages {
    stage('Pull') {
      steps {
        sh 'git pull origin 7.x-1.x --tags'
        sh 'git pull origin 7.x-1.x'
      }
    }
    stage('Push') {
      steps {
        sh 'git push git@git.drupal.org:project/byu_installation_profile.git HEAD:refs/heads/7.x-1.x'
        sh 'git push git@git.drupal.org:project/byu_installation_profile.git --tags'
      }
    }
  }
}
